#include <Arduino.h>
#include "Morse_Gen.h"

class Transmitter{
  unsigned long end_of_interval_micros;                         
  unsigned long TOS_micros;
  const int MULT=10;
  unsigned long interval=1000000/MULT;
  int interval_count=0;

  Morse_Gen gen;
  
  public: Transmitter(byte T){
    gen.setTransmitPin(T);
  }
  
  public: void TransmitInput() {
    if(micros() >= end_of_interval_micros && interval_count<MULT){
          gen.tick_clock();
          interval_count++;
          end_of_interval_micros += interval;
    }
  }
  public: void getInput(){
    gen.add_new_input(gen.Get_Input());
  }
  public: void resetSecond(){
    interval_count = 0;
    TOS_micros = micros();
    end_of_interval_micros = TOS_micros+interval;
  }
};
