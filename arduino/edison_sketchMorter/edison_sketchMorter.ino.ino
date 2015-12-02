//
//  socket.ioからの信号で、モーター制御を行う
//  0→停止、1→前進、2→後退（3→ブレーキ？）となっています
//  app.jsのあるEdisonに書き込んでください。
//

#include <WiFi.h>

WiFiServer server(3000);
char c = '0';

//const int pinLed    = 7;  //7番に変更
const int motorA = 3;
const int motorB = 4;

void setup() {
  
  Serial.begin(9600);
//  pinMode(pinLed,OUTPUT);
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
    
  server.begin();
  Serial.print("Connected to TCP. My address:");
  IPAddress myAddress(127,0,0,1);
  //IPAddress myAddress(192,168,11,24);
  Serial.println(myAddress);
  
}


void loop() {      
  
  WiFiClient client = server.available();
      
    if (client.available() > 0){
      
        c = client.read();
        //if (c == '1') 
        if (c == '0') {
           //digitalWrite(pinLed, HIGH);
           //STOP
           digitalWrite(motorA,LOW);
           digitalWrite(motorB,LOW);
        } 
        //if (c == '1') 
        if (c == '1') {
           //digitalWrite(pinLed, LOW);
           //GO
           digitalWrite(motorA,HIGH);
           digitalWrite(motorB,LOW);
        }
        if (c == '2') {
          //BACK
           digitalWrite(motorA,LOW);
           digitalWrite(motorB,HIGH);
        }
        if (c == '3') {
           //BRAKE
           digitalWrite(motorA,HIGH);
           digitalWrite(motorB,HIGH);
        }
    }
    
  Serial.println(c);
  delay(10);
    
}

