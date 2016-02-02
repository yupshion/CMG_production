#include <WiFi.h>
#include <Servo.h>

WiFiServer server(3000);
char c = '0';

// Use a Servo object to represent and control the servo.
Servo groveServo;


//const int pinLed    = 7;  //7番に変更したよ
//const int motorA = 3;
//const int motorB = 4;

const int pinServo = 5;
const int potentiometer = 0;
int angle = 90;

void setup() {
  
  Serial.begin(9600);
//  pinMode(pinLed,OUTPUT);
//  pinMode(motorA,OUTPUT); //信号用ピン
//  pinMode(motorB,OUTPUT); //信号用ピン
  
  //サーボのピン設定
  groveServo.attach(pinServo);
  
  //角度センサーのピン設定
  pinMode(potentiometer, INPUT);
    
  server.begin();
  Serial.print("Connected to TCP. RotaryAngle to Servo.");
  Serial.print("My address:");
  IPAddress myAddress(127,0,0,2);
  Serial.println(myAddress);
  
}


void loop() {      
  
  WiFiClient client = server.available();

 // 角度センサーから値を読み取ります。
  int sensorPosition = analogRead(potentiometer);

 // 値の対応付け
  int shaftPosition = map(sensorPosition, 0, 1023, 0, 179);

 // 書き込み
   groveServo.write(shaftPosition);

 // 待ち
   delay(15);

  Serial.println(shaftPosition);
  delay(10);
   


/*

      
    if (client.available() > 0){
      
        c = client.read();
        //if (c == '1') 
        if (c == '0') {
           //digitalWrite(pinLed, HIGH);
           //STOP
           digitalWrite(motorA,LOW);
           digitalWrite(motorB,LOW);
           groveServo.write(9
           0);
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
  */
  

}

