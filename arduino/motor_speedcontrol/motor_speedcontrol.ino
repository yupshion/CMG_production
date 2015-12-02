// 距離センサによるモーター制御
const int motorA = 9;
const int motorB = 10;
const int trigPin = 7;
const int echoPin = 4;
const int PWM_mot = 3;
void setup(){
  Serial.begin(9600);
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop(){
    long duration, distance;
      digitalWrite(trigPin, LOW);  // Added this line
      delayMicroseconds(100); // Added this line
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(100); // Added this line
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;
      Serial.println(distance);
     if (distance >= 20) {  // STOP
        digitalWrite(motorA, LOW);
        digitalWrite(motorB, LOW);
     }   
      else if (distance > 0 && distance < 20){
        digitalWrite(motorA,HIGH); 
        digitalWrite(motorB,LOW);
        analogWrite(PWM_mot, 255 * distance / 20);        
      }
      if (distance >= 200 || distance <= 0){
        Serial.println("Out of range");
      }
      else {
        Serial.print(distance);
        Serial.println(" cm");
      }
}
