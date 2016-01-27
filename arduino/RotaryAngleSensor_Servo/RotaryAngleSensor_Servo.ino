//
//  デジタル3番ピンにサーボを接続して、アナログ角度操作器でサーボを動かすコードです
//

// Demo of Grove - Starter Kit V2.0
//￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥［［［［［［／／／／／／／／／／［
// Uses the Grove - Rotary Angle Sensor to control the position of the Grove - Servo.
// Connect the Grove - Servo to the socket marked D3
// Connect the Grove - Rotary Angle Sensor to A0
// サーボをD3に接続し、角度センサーをA0に接続します。

#include <Servo.h>

// Define the pins to which the servo and sensor are connected.
// サーボとセンサーの接続ピンを設定します。
const int pinServo = 3;
const int potentiometer = 0;

// Use a Servo object to represent and control the servo.
// サーボを使うために、サーボオブジェクトを宣言します。
Servo groveServo;

void setup()
{
    // Tell the Servo object which pin to use to control the servo.
    // どのピンでサーボをコントロールするか設定します。
    groveServo.attach(pinServo);

    // Configure the angle sensor's pin for input signals.
    // 角度センサーのピンを設定します。
    pinMode(potentiometer, INPUT);
}

void loop()
{
    // Read the value of the angle sensor.
    // 角度センサーから値を読み取ります。
    int sensorPosition = analogRead(potentiometer);

    // The analog value from the angle sensor is between 0 and 1023, but
    // the servo only accepts values between 0 and 179; use the map()
    // function as a linear conversion between the two ranges.
    int shaftPosition = map(sensorPosition, 0, 1023, 0, 179);


    // Use the Servo object to move the servo.
    groveServo.write(shaftPosition);

    delay(15);
}
