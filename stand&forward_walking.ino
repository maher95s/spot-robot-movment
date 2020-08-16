/*
Spot Micro Robot
stand & forward walking
by : eng.Maher sharaf
youtube channel : https://www.youtube.com/channel/UCfH96a56nestB0j0xEdz7wA?disable_polymer=true
instagram account : Spot.robot
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN  120 //120 50hz
#define SERVOMAX  550 //550 50hz

const int Rf1=14 , Rf2=15 , Rf3=13 ;
const int Rb1=1 , Rb2=0 , Rb3=7 ;
const int Lf1=10 , Lf2=11 , Lf3=9 ;
const int Lb1=5 , Lb2=4 , Lb3=6 ;
int st=0;

void setup() {
Serial.begin(9600);
Serial.println("walk test!");
pwm.begin();
pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
stand();
//yield();
delay(5000);
}

void loop() {
stand();  
//step_forward();
//test2();
}

void stand(){
pwm.setPWM(Rf1 , 0 , angleToPulse(85) );
pwm.setPWM(Rf2 , 0 , angleToPulse(55) );
pwm.setPWM(Rf3 , 0 , angleToPulse(94) );
pwm.setPWM(Lf1 , 0 , angleToPulse(82) );
pwm.setPWM(Lf2 , 0 , angleToPulse(90) );
pwm.setPWM(Lf3 , 0 , angleToPulse(49) );
pwm.setPWM(Rb1 , 0 , angleToPulse(62) );
pwm.setPWM(Rb2 , 0 , angleToPulse(50) );
pwm.setPWM(Rb3 , 0 , angleToPulse(70) );
pwm.setPWM(Lb1 , 0 , angleToPulse(83) );
pwm.setPWM(Lb2 , 0 , angleToPulse(90) );
pwm.setPWM(Lb3 , 0 , angleToPulse(66) );  
}

void step_forward(){

pwm.setPWM(Lb3 , 0 , angleToPulse(36) );
pwm.setPWM(Rf3 , 0 , angleToPulse(120) );
delay(50);
pwm.setPWM(Lb2 , 0 , angleToPulse(70) );
pwm.setPWM(Rf2 , 0 , angleToPulse(68) );
delay(50);
pwm.setPWM(Lb3 , 0 , angleToPulse(66) );
pwm.setPWM(Rf3 , 0 , angleToPulse(94) );
delay(500);
pwm.setPWM(Lb2 , 0 , angleToPulse(80) );
pwm.setPWM(Lb3 , 0 , angleToPulse(66) );
pwm.setPWM(Rf2 , 0 , angleToPulse(55) );
pwm.setPWM(Rf3 , 0 , angleToPulse(94) );

//***************

pwm.setPWM(Rb3 , 0 , angleToPulse(95) );
pwm.setPWM(Lf3 , 0 , angleToPulse(20) );
delay(50);
pwm.setPWM(Rb2 , 0 , angleToPulse(60) );
pwm.setPWM(Lf2 , 0 , angleToPulse(77) );
delay(50);
pwm.setPWM(Rb3 , 0 , angleToPulse(70) );
pwm.setPWM(Lf3 , 0 , angleToPulse(49) );
delay(500);
pwm.setPWM(Lf2 , 0 , angleToPulse(90) );
pwm.setPWM(Lf3 , 0 , angleToPulse(49) );
pwm.setPWM(Rb2 , 0 , angleToPulse(50) );
pwm.setPWM(Rb3 , 0 , angleToPulse(70) );
}

//***********************************
int angleToPulse(int ang){
   int pulse = map(ang ,0 , 180 , SERVOMIN , SERVOMAX );
   Serial.print("Angle: "); Serial.print(ang);
   Serial.print(" pulse: "); Serial.println(pulse);
   return pulse;
}
