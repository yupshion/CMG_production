#include <WiFi.h>
#include <Servo.h>

WiFiServer server(3000);
//char c = '0';
char c = '0';

// Use a Servo object to represent and control the servo.
Servo groveServo;


//const int pinLed    = 7;  //7番に変更したよ
const int motorA = 3;
const int motorB = 4;
const int pinServo = 5;
int angle = 90;

void setup() {
  
  Serial.begin(9600);
//  pinMode(pinLed,OUTPUT);
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
  groveServo.attach(pinServo);
    
  server.begin();
  Serial.print("Connected to TCP. My address:");
  IPAddress myAddress(127,0,0,1);
  //IPAddress myAddress(192,168,11,24);
  Serial.println(myAddress);
  groveServo.write(120);
  
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
           groveServo.write(90);
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
           groveServo.write(90);
        }
        //左右の動作制御
        if (c == '4') {
          // Use the Servo object to move the servo.
          //if(angle < 150)
          //  angle += 30;
          groveServo.write(30);
          delay(500);

        }
        if (c == '5') {
          // Use the Servo object to move the servo.
          //if(angle > 30)
          //  angle -= 30;
          groveServo.write(140);
          delay(500);
        }
    }
  
  Serial.println(c);
  delay(10);
    
}

