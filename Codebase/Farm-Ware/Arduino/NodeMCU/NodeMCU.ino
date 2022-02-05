#include<SoftwareSerial.h>
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include<ArduinoJson.h>
#include"stdio.h"

SoftwareSerial Node(D2,D3);//rx,tx

#define FIREBASE_HOST "farmware-4ee04.firebaseio.com"
#define FIREBASE_AUTH "8YhB3YFXFgIXIbpsAIPuAreRtfG2z3x8frbFls19"
#define WIFI_SSID "Redmi Note 5 Pro"
#define WIFI_PASSWORD "3FD1726C"

void setup() {
  Serial.begin(9600);
  Node.begin(4800);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);


  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}
int n=0;
String myString1;

void loop() {
 //float val1;
 //Node.available()==1;
 Node.write("Node");
 //Node.available()==1;
 if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
   
  Serial.print("Rain Drop:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Raindrop:",myString1);
  //}
  }else
  Serial.print(1);
 
  if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
  Serial.print("Temperature:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Temperature:",myString1);
  }
  if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
  Serial.print("Humidity:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Humidity:",myString1);
  }
  if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
  Serial.print("Soil Moisture:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Soil Moisture:",myString1);
  }
  if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
  Serial.print("Water Level:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Water Level:",myString1);
  }
  if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
  Serial.print("Frequency:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Frequency:",myString1);
  }
  if(Node.available()>0){
  float val1 = Node.read();
  
  //if(Node.read()=='\n'){
  Serial.print("Total:");
  Serial.println(val1);
 
  myString1 = String(val1);
  
  Firebase.setString("Total:",myString1);
  }
  

  //float val2 = Node.parseFloat();
  
  //if(Node.read()=='\n'){
  //Serial.println(val2);
 
  //String myString2 = String(val2);
  
  //Firebase.setString("Temperature:",myString2); 
  //}
  //set value
  /*Firebase.setFloat("number", val1);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(100);
  


  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(100);


  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);*/
 
  //Node.available()==1;
  delay(5000); 
} 
