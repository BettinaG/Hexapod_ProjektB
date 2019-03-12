#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 130
#define SERVOMAX 600

#define ELEMENTS 6

#define TOP_MOTORS 0
#define BOTTOM_MOTORS 6
#define INNER_MOTORS 12

Servo innerServo4,
      innerServo5;

int lastDegBot[ELEMENTS],
    lastDegTop[ELEMENTS],
    lastDegIn[ELEMENTS],

    degsBot[ELEMENTS],
    degsTop[ELEMENTS],
    degsIn[ELEMENTS],

    pulse;

char input,
     order;         // f = forward, b = backward, r = reset
