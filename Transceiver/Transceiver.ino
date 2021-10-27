#include "Receiver.h"
#include "Transmitter.h"

//Things to update if needed
const byte PPSPin = 2;
const byte receiverPin = A12; //Pin 26
const float logicLevel = 0.03;
const long freq = 800; //Hz
const byte transmitPin = 4;

//Never change below
const byte ledPin = 13;
volatile byte state = LOW;
long prevMicros;
int n;

Receiver R(receiverPin,logicLevel,freq);
Transmitter T(transmitPin);

void setup() {
  Serial.begin(9600);
  n = R.getN();
  R.setNPerS(n*10);
  R.produceDFT();
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PPSPin), ISR, RISING);
  while(state == LOW){}//wait for first pps from GPS
  prevMicros = 0;
}

void loop() {
  prevMicros = R.ReceiveData(prevMicros);
  R.processData(n);
  //T.getInput();
  //T.TransmitInput();
}

void ISR() {
  digitalWrite(ledPin, state); //Commented out to send Transmit output on it
  state = !state;
  R.setDataPerS(0);
  T.resetSecond();
}
