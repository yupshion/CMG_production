// モーター制御
// 一定時間ごとに動作を切り替えます

const int motorA = 3;
const int motorB = 4;
//const int PWM_mot = 9;
void setup(){
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
}

void loop(){
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    delay(1000);
    digitalWrite(motorA,HIGH);
    digitalWrite(motorB,LOW);
  //  analogWrite(PWM_mot,100); 
    delay(3000);
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,LOW);
    delay(1000);
    digitalWrite(motorA,LOW);
    digitalWrite(motorB,HIGH);
   // analogWrite(PWM_mot,100); 
    delay(3000);
}
