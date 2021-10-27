#include "dataCollection.h"
#include "DFT.h"
#include "Translator.h"

class Receiver{
  private: int dataPerSec = 0;
  int count = 0;
  int nPerS;
  
  //Creation of Objects for further "Threading"
  DFT dft;
  dataCollection dc;
  Translator Trans;
  
  public: Receiver(byte R, float LL, long F){
    dc.setReceiverPin(R);
    dft.setLogicLevel(LL);
    dft.setFreq(F);
  }

  public: long ReceiveData(long prevMicro){
    if(dataPerSec < nPerS){ //if you've taken less data than you expect to in a second
      if(micros() - prevMicro >= 125){
        dc.voltage(count++);
        return micros();
      }
    }
    return prevMicro;
   }

  public: void processData(int n){
    if(count == n){ //reset array and perform DFT
      float temp = dft.DFTMath(dc.getVdata());
      Trans.newData(dft.DFTLogic(temp));
      //Serial.println(temp);
      dc.resetVdata();
      count = 0;
      dataPerSec += n;
      Serial.println();
    }
  }

  public: void setDataPerS(int d){dataPerSec = d;}
  public: void setNPerS(int n){nPerS = n;}
  public: int getN(){return dft.getN();}
  public: void produceDFT(){dft.produceDFT(dft.getN());}
};
