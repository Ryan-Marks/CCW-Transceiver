#include <Arduino.h>
#include "Morse_Gen.h"

class Transmitter{
  unsigned long end_of_interval_micros; // end of each time segment                                 
  unsigned long TOS_micros;// Top of second microseconds from ISR
  const int MULT=10;  // frequency multiplier within UTC second.  10 give 100 ms intervals: 12 WPM Morse
  unsigned long interval=1000000/MULT; // i.e., 100,000 for MULT=10 for 12 WPM. Use this to adjust timing.
                                       // 100000 is for perfect Arduino clock.
                                       // Compare this with interrupt clock for adjustments.
  int interval_count=0;
    // Class   Object    declaration
  Morse_Gen gen; // object to be serviced at each timeslice
  
  public: Transmitter(byte T){
    gen.setTransmitPin(T);
  }
  
  public: void TransmitInput() {
    if(interval_count<MULT && micros() >= end_of_interval_micros){
          gen.tick_clock();
          interval_count++;
          end_of_interval_micros += interval;
    }
  }
  public: void getInput(){
    String input = gen.Get_Input();
    gen.add_new_input(input);
  }
  public: void resetSecond(){
    interval_count = 0;
    end_of_interval_micros = TOS_micros+(interval*(MULT+1));
    TOS_micros = micros();
  }
};
