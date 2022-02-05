#include"Arduino.h"
#include "DHT.h"  
#include <SoftwareSerial.h>
#include"stdio.h"
#include<Wire.h>
//#include<WiFi.h>
#include<SPI.h>
//String f;
DHT dht; 

SoftwareSerial ArduinoSerial(0 /*RX*/,1 /*TX*/);

void setup() {   
  Serial.begin(9600);
  ArduinoSerial.begin(4800);
  dht.setup(4);
  pinMode(analogRead(A3),INPUT);
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
}

void loop() {
  //ArduinoSerial.write("ArduinoSerial");
  //while(ArduinoSerial.available()>0){

  //RainDrop Start
  float RD_sensorValue = analogRead(A0);
  Serial.print("Raindrop:");
  if (ArduinoSerial.available()>0){
   ArduinoSerial.write(RD_sensorValue);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  Serial.println(RD_sensorValue);
  
  //RainDrop End
  
  //DHT22 Start
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("*c");
  
  Serial.print("  Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  //DHT22 End

  //SoilMoisture Start
  float  SM_sensorValue = analogRead(A1);
  float  SM_outputValue = map(SM_sensorValue, 0, 1023, 100, 0);
  Serial.print("Soil Moisture: ");
  Serial.print(SM_outputValue);
  Serial.println("%");
  
  //SoilMoisture End

  //WaterLevel Start
  float WL_sensorValue = analogRead(A2);
  int WL_outputValue = map(WL_sensorValue, 0, 1023, 0, 40);
  Serial.print("Water Level:");
  Serial.println(WL_outputValue); 
  
  //WaterLevel End

  //WaterFlow Start
  int X = pulseIn(analogRead(A3), HIGH);
  int Y = pulseIn(analogRead(A3), LOW);
  float TIME = X + Y;
  float FREQUENCY = 1000000/TIME;
  float WATER = FREQUENCY/7.5;
  float LS = WATER/60;
  float TOTAL=0.00;
  
  if(FREQUENCY >= 0)
  {
  if(isinf(FREQUENCY))
  {
  Serial.println("VOL. :0.00");
  Serial.print("TOTAL:");
  Serial.print(TOTAL);
  Serial.println(" L");
  //if (ArduinoSerial.available()>0){
  //ArduinoSerial.println(TOTAL);
  //ArduinoSerial.print('\n');
  //}
  }
  else
  {
  float TOTAL = TOTAL + LS;
  Serial.println(FREQUENCY);
  Serial.print("VOL.: ");
  Serial.print(WATER);
  Serial.println(" L/M");
  
  Serial.print("TOTAL:");
  Serial.print( TOTAL);
  Serial.println(" L");
  
  }
  }
  
  
  if (ArduinoSerial.available()>0){  
  ArduinoSerial.println(temperature);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  if (ArduinoSerial.available()>0){
  ArduinoSerial.println(humidity);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  if (ArduinoSerial.available()>0){
  ArduinoSerial.println(SM_outputValue);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  if (ArduinoSerial.available()>0){
  ArduinoSerial.println(WL_outputValue);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  if (ArduinoSerial.available()>0){
  ArduinoSerial.println(FREQUENCY);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  if (ArduinoSerial.available()>0){
  ArduinoSerial.println(TOTAL);
  ArduinoSerial.print('\n');
  //ArduinoSerial.available()==1;
  delay(1000);
  }
  delay(2000);

  
  //}
  
}
