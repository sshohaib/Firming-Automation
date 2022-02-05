#include "DHT.h"                        //include the DHT library
#include <stdio.h>
#include <LiquidCrystal.h>              //include the LiquidCrystal library
#define DHTPin 2                        //define DHT pin
LiquidCrystal lcd(1, 3, 4, 5, 6, 7);    //define LCD pins (RS, E, D4, D5, D6, D7)
DHT dht;

void setup() {
  dht.setup(DHTPin);  
  Serial.begin(9600);                      //initializes the LCD and specifies the dimensions
}
void loop() {
  float temp = dht.getTemperature();
  float humi = dht.getHumidity();
  Serial.print("  Temperature: ");
  Serial.print(dht.getTemperature());
  Serial.print("*c");
  Serial.print("  Humidity: ");
  Serial.print(dht.getHumidity());
  Serial.println("%");
  delay(2000);
}
