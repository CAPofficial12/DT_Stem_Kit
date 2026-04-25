#include <Arduino.h>
#include <Servo.h>
#include <MPU6050.h>
#include <Wire.h>

// All 4 servos
Servo servoTL;
Servo servoTR;
Servo servoBL;
Servo servoBR;

MPU6050 imu;

int t1;
int t2;

int target;
int tilt;

void fix_pos(int x){}

void setup() {

  imu.CalibrateAccel();
  imu.CalibrateGyro();

  servoTL.attach(0);
  servoTR.attach(1);
  servoBL.attach(2);
  servoBR.attach(3);
}

void loop() {
  t1 = millis();
  fix_pos(90);
}

void fix_pos(int x) {
  servoTL.write(x);
  servoTR.write(x);
  servoBL.write(x);
  servoBR.write(x);
}