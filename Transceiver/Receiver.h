#include "dataCollection.h"
#include "DFT.h"
#include "Translator.h"

class Receiver{
  private: int dataPerSec = 0;
  int count = 0;
  int nPerS;
  unsigned long end_of_interval_micros;                            
  unsigned long TOS_micros;
  unsigned long interval=100000 - 10;
  unsigned long curr_micros;
  
  //Creation of Objects
  DFT dft;
  dataCollection dc;
  Translator Trans;
  
  public: Receiver(byte R, float LL, long F){
    dc.setReceiverPin(R);
    dft.setLogicLevel(LL);
    dft.setFreq(F);
  }

  public: long ReceiveData(long prevMicro){
    curr_micros = micros();
    if(dataPerSec < nPerS && curr_micros < end_of_interval_micros){
      if(curr_micros - prevMicro >= 125){
        dc.voltage(count++);
        return curr_micros;
      }
    }
    return prevMicro;
   }

  public: void processData(int n){
    float curr_micros = micros();
    if(count == n || curr_micros >= end_of_interval_micros){
      end_of_interval_micros += interval;
      Trans.newData(dft.DFTLogic(dft.DFTMath(dc.getVdata())));
      
      //May need to reset Vdata to 0 instead of character null
      dc.resetVdata();
      
      count = 0;
      dataPerSec += n;
      //Serial.println();
    }
  }

  public: void resetSecond(){
    dataPerSec = 0;
    TOS_micros = micros();
    end_of_interval_micros = TOS_micros + interval;
  }
  public: void setNPerS(int n){nPerS = n;}
  public: int getN(){return dft.getN();}
  public: void produceDFT(){dft.produceDFT(dft.getN());}
};
