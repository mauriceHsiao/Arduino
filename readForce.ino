#include <time.h>

//A0-input pin
int fsrPin0 = 0;
int fsrPin1 = 2;
int fsrPin2 = 4;
int fsrPin3 = 6;
int fsrPin4 = 8;
int fsrPin5 = 10;
int fsrPin6 = 12;
int fsrPin7 = 13;
int fsrPin8 = 14;
int fsrPin9 = 15;

int fsrReading;
double fsrVoltage;
double fsrResistance;
double fsrConductance;
double fsrForcelb;
double fsrForceN;
unsigned long startTime; 
unsigned long endTime;

double fsrReading0;
double fsrReading1;
double fsrReading2;
double fsrReading3;
double fsrReading4;
double fsrReading5;
double fsrReading6;
double fsrReading7;
double fsrReading8;
double fsrReading9;

void setup(){
  pinMode(fsrPin0,INPUT);
  pinMode(fsrPin1,INPUT);
  pinMode(fsrPin2,INPUT);
  pinMode(fsrPin3,INPUT);
  pinMode(fsrPin4,INPUT);
  pinMode(fsrPin5,INPUT);
  pinMode(fsrPin6,INPUT);
  pinMode(fsrPin7,INPUT);
  pinMode(fsrPin8,INPUT);
  pinMode(fsrPin9,INPUT);
  Serial.begin(115200);
}

void loop(){
  //startTime = millis();
  /*
  readForce(fsrPin0);
  readForce(fsrPin1);
  readForce(fsrPin2);
  readForce(fsrPin3);
  readForce(fsrPin4);
  readForce(fsrPin5);
  readForce(fsrPin6);
  readForce(fsrPin7);
  */
  fsrReading0 = analogRead(fsrPin0);
  fsrReading1 = analogRead(fsrPin1);
  fsrReading2 = analogRead(fsrPin2);
  fsrReading3 = analogRead(fsrPin3);
  fsrReading4 = analogRead(fsrPin4);
  fsrReading5 = analogRead(fsrPin5);
  fsrReading6 = analogRead(fsrPin6);
  fsrReading7 = analogRead(fsrPin7);
  fsrReading8 = analogRead(fsrPin8);
  fsrReading9 = analogRead(fsrPin9);
  Serial.print(fsrReading0);
  Serial.print(",");
  Serial.print(fsrReading1);
  Serial.print(",");
  Serial.print(fsrReading2);
  Serial.print(",");
  Serial.print(fsrReading3);
  Serial.print(",");
  Serial.print(fsrReading4);
  Serial.print(",");
  Serial.print(fsrReading5);
  Serial.print(",");
  Serial.print(fsrReading6);
  Serial.print(",");
  Serial.print(fsrReading7);
  Serial.print(",");
  Serial.print(fsrReading8);
  Serial.print(",");
  Serial.print(fsrReading9);
  Serial.println("");
  delay(5);
  //endTime= millis() - startTime;
  //Serial.print(endTime);
  //Serial.println(" microseconds");
  //Serial.println("--------------------------");
}

void readForce(int fsrPin){
  //Receive analog reading.
  fsrReading = analogRead(fsrPin);
  //Serial.print("Analog ");
  //Serial.print(fsrPin);
  //Serial.print(" reading = ");
  Serial.println(fsrReading);

  /*
  //Translate analog reading to Voltage(mV).
  fsrVoltage = float(map(fsrReading,0,1023,0,5000));
  Serial.print("Voltage ");
  Serial.print(fsrPin);
  Serial.print(" reading in mV = ");
  Serial.println(fsrVoltage);
  fsrResistance = (10000000*(5000-fsrVoltage))/fsrVoltage;
  fsrConductance = 1000000/fsrResistance;  
  
  fsrForcelb = (fsrConductance-0.0012)/0.00014;
  Serial.print("Force ");
  Serial.print(fsrPin);
  Serial.print(" lb = ");
  Serial.println(fsrForcelb);
  
  fsrForceN = fsrForcelb * 4.4;
  Serial.print("Force ");
  Serial.print(fsrPin);
  Serial.print(" N = ");
  Serial.println(fsrForceN);
  */
}

