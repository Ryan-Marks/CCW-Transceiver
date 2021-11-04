class dataCollection{
  int receiverPin = A12;
  float Vdata[800];
  public: boolean flag = false;

  public: dataCollection(int RP){
    receiverPin = RP;
    pinMode(receiverPin, INPUT);
  }
  public: dataCollection(){}
  
  float returnVoltage() {
    //This method is for testing purposes only
    return analogRead(receiverPin) * (3.3 / (float)1024);
  }
  
  void voltage(int i) {
    Vdata[i] = analogRead(receiverPin) * (3.3 / (float)1024);
    //Serial.println(Vdata[i]);
    //Serial.print(", ");
  }

  
  float getVdata(int i) {return Vdata[i];}
  float* getVdata() {return Vdata;}
  void resetVdata() {
    memset(Vdata, 0, sizeof(Vdata));
  }
  int getReceiverPin(){return receiverPin;}
  void setReceiverPin(int RP){
    receiverPin = RP;
    pinMode(receiverPin, INPUT);
  }
};
