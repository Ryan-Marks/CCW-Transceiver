#include <CComplex.h>

class DFT{
  const static int N = 800;
  int FREQ;
  int DFTRow;
  Complex DFTMatrix[N]; //= new Complex[freq];
  Complex dataPostDFT[N];
  float logicLevel = 0.25;
  public: boolean flag = true;

  public: DFT(float LL, long f){
    logicLevel = LL;
    FREQ = f;
    DFTRow = FREQ /10;
  }
  public: DFT(){}
  
  public: void produceDFT(int n){
    Complex c;
    for(int i = 0; i < n; i++){
      c.set(0,((float)(i)*2*PI*DFTRow)/(float)(n));
      DFTMatrix[i] = c.c_exp();
      //Serial.print(DFTMatrix[i]);
      //Serial.print(", ");
    }
    //Serial.println();
  }

  public: float DFTMath(float* Data){
    Complex averageSum = 0;
    for(int i = 0; i < N; i++){
      averageSum.set(averageSum.real() + (DFTMatrix[i].real() * Data[i]),averageSum.imag() + (DFTMatrix[i].imag() * Data[i]));
    }
    //averageSum /= N;
    //Serial.print(averageSum.modulus()); //Used for testing for LogicLevel
    //Serial.print(", ");
    return averageSum.modulus();
  }

  int DFTLogic(float input){return (input > logicLevel) ? 1:0;}

  float getLogicLevel() {return logicLevel;}
  void setLogicLevel(float LL) {logicLevel = LL;}
  int getN(){return N;}
  int getFreq(){return FREQ;}
  void setFreq(int f){FREQ = f;DFTRow = FREQ/10;}
};
