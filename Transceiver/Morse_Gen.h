#include "MorseCharacter.h"
#include <LinkedListLib.h>
//#include "Get_char_from_Python.h"

class Morse_Gen {
  bool ready_for_new_char = true;
  String Morse_queue="";
  char c;
  String MorseString="";
  LinkedList<int> timing_queue = LinkedList<int>();
  
  byte TRANSMIT_PIN = 4;
  bool send_to_LED = true; // have code sent to LED
  bool send_to_transmitter = true; // don't transmit until command sent
  bool send_to_tone_generator = false; // generate tones until command sent

  // Counters for number of key down and up time slots:
  int remaining_ticks = 0;

  MorseCharacter MC;

  public: Morse_Gen(byte T){
    TRANSMIT_PIN = T;
    pinMode(T,OUTPUT);
  }
  public: Morse_Gen(){}

  public: setTransmitPin(byte T){
    TRANSMIT_PIN = T;
    pinMode(T,OUTPUT);
  }
  
  private: void key_up() { // do the shutoffs regardless of _send_to states
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(TRANSMIT_PIN, LOW); // un-key MOSFET on transmit line
  }
  void key_dn() {
    if (send_to_LED) { // if code is to be sent to the LED
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (send_to_transmitter) { // digital write to the keying transistor
      digitalWrite(TRANSMIT_PIN, HIGH); // as above, key MOSFET on transmit line
    }
  }

public:
  bool new_char(){return ready_for_new_char;}
  String get_Morse_queue(){return Morse_queue;}
  
  void set_Morse_queue(String str)  { // Setter method
    Morse_queue=str;
  }

  String Get_Input()  {
    if(Serial.available() > 0) {
        return Serial.readString();
    }
  }

  void add_new_character(char c){
    Morse_queue.concat(c); // Sets up FIFO queue.
  }

  void add_new_input(String s){
    Morse_queue.concat(s);
  }

  void set_send_to_LED(bool S){send_to_LED=S;}
  void set_send_to_transmitter(bool S){send_to_transmitter=S;}
  void set_send_to_tone_generator(bool S){send_to_tone_generator=S;}

  void tick_clock(){
    if(Morse_queue.length() > 0){
      MorseString.concat(MC.MorseFromCharacter(Morse_queue.charAt(0))); // FIFO buffer
      Morse_queue.remove(0,1);
    }
    
    if (MorseString.length()>0) {
      if (MorseString.substring(0,2) == "SP"){ // Space: prepare key up time
        timing_queue.InsertTail(-4);
        MorseString.remove(0,2);
      } else if (MorseString.charAt(0)=='.') {
        timing_queue.InsertTail(1);
        timing_queue.InsertTail(-1);
        MorseString.remove(0,1);
      } else if(MorseString.charAt(0) == '-'){
        timing_queue.InsertTail(3);
        timing_queue.InsertTail(-1);
        MorseString.remove(0,1);
      }
      if (MorseString.charAt(0)== 'E') {
          timing_queue.InsertTail(-2);
          MorseString.remove(0,1);
      }
    }
    if(timing_queue.GetSize() > 0){
      for(int i = 0; i < timing_queue.GetSize();i++){
        Serial.print(timing_queue.GetAt(i));
        Serial.print(", ");
      }
      Serial.println();
      Serial.println(remaining_ticks);
    } 
    if(remaining_ticks == 0){
      if(timing_queue.GetSize() == 0){key_up();return;}
      remaining_ticks = timing_queue.GetHead();
      timing_queue.RemoveHead();
    }
    if(remaining_ticks > 0){
      key_dn();
      remaining_ticks--;
      return;
    }
    if(remaining_ticks < 0){
      key_up();
      remaining_ticks++;
      return;
    }
  }
};
