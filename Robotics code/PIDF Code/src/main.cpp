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
int lastTilt;

double Kp;
double error;
double P;

double Kd;
double dt;
double derivative;
double D;

double Ki;
double integral;
double I;

double Kf;

void fix_pos(int x);
void set_power(int x);

void setup() {

  imu.CalibrateAccel();
  imu.CalibrateGyro();
  target = imu.getRotationY();
  servoTL.attach(0);
  servoTR.attach(1);
  servoBL.attach(2);
  servoBR.attach(3);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6,   OUTPUT);
  pinMode(7, OUTPUT);

  lastTilt = imu.getRotationY() - target;
}

void loop() {
  t1 = millis();
  fix_pos(90);

  tilt = angl();
  error = tilt - target;

  dt = millis() - t1;
  if (dt == 0){
    dt = 1;
  }

  
  integral += error * dt;
  I = Ki * integral;

  derivative  = (tilt - lastTilt)/dt;
  double out = Kp*error + Kd*derivative;
  Serial.println(out);

  set_power(out);
  lastTilt = tilt;
}

void fix_pos(int x) {
  servoTL.write(x);
  servoTR.write(x);
  servoBL.write(x);
  servoBR.write(x);
}

void set_power(int x){
  analogWrite(4,x);
  analogWrite(5,x);
  analogWrite(6,x);
  analogWrite(7,x);
}

double angl(){
  double angle = 0;
  float alpha = 0.98;

  float accelAngle = atan2(imu.getAccelerationX(), imu.getAccelerationZ()) * 180/PI;
  float gyroRate = imu.getRotationY() / 131.0; // 131 LSB/(°/s) at ±250°/s
  angle = alpha * (angle + gyroRate * dt/1000.0) + (1 - alpha) * accelAngle;
  return angle;
}