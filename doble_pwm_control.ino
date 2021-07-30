#include <Servo.h>

Servo out;

int inPwm1 = A0;
int inPwm2 = A1;
int duracionPwm1;
int duracionPwm2;
int valOut = 1500;

void setup() {
  Serial.begin(9600);

  pinMode(inPwm1, INPUT);
  pinMode(inPwm2, INPUT); 

  out.attach(9);
  out.writeMicroseconds(valOut);
}

void loop() {
  duracionPwm1 = pulseIn(inPwm1, HIGH); 
  duracionPwm2 = pulseIn(inPwm2, HIGH);

  if (duracionPwm1 > 1700 && duracionPwm2 > 1400 && duracionPwm2 < 1600) {
    valOut = 2000;
    out.writeMicroseconds(valOut);
  }

  if (duracionPwm2 > 1700 && duracionPwm1 > 1400 && duracionPwm1 < 1600) {
    valOut = 1000;
    out.writeMicroseconds(valOut);
  }

  if (duracionPwm1 > 1700 && duracionPwm2 > 1700) {
    valOut = 1500;  
    out.writeMicroseconds(valOut);
  }

  if (duracionPwm1 > 1400 && duracionPwm1 < 1600 && duracionPwm2 > 1400 && duracionPwm2 < 1600) {
    valOut = 1500;
    out.writeMicroseconds(valOut);
  }
  Serial.println(valOut);
}
