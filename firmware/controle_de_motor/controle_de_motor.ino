#include <Arduino.h>

// Motor 1 and Motor 2 Pin Definitions
#define MOTOR1_IN1 18  
#define MOTOR1_IN2 19  
#define MOTOR2_IN1 23  
#define MOTOR2_IN2 27  

void setup() {
  // Set motor pins as outputs
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
}

void loop() {
  // Motor 1: Forward (speed control with PWM)
  digitalWrite(MOTOR1_IN1, LOW);          // Direction Forward
  analogWrite(MOTOR1_IN2, 150);           // Speed: between 0-255
  digitalWrite(MOTOR2_IN1, LOW);          // Direction Forward
  analogWrite(MOTOR2_IN2, 150);           // Speed: between 0-255
  delay(2000);                            // Run for 2 seconds

  // Stop motor 1
  analogWrite(MOTOR1_IN1, 0);
  analogWrite(MOTOR1_IN2, 0);
  analogWrite(MOTOR2_IN1, 0);
  analogWrite(MOTOR2_IN2, 0);
  delay(2000);                             // Wait 2 seconds

  // Motor 1: Reverse (speed control with PWM)
  digitalWrite(MOTOR1_IN2, LOW);           // Direction: Backward
  analogWrite(MOTOR1_IN1, 150);            // Speed: between 0-255
  digitalWrite(MOTOR2_IN2, LOW);           // Direction: Backward
  analogWrite(MOTOR2_IN1, 150);            // Speed: between 0-255
  delay(2000);
  
  // Stop motors
  analogWrite(MOTOR1_IN2, 0);
  analogWrite(MOTOR1_IN1, 0);
  analogWrite(MOTOR2_IN2, 0);
  analogWrite(MOTOR2_IN1, 0);
  delay(2000);                             // Wait 2 seconds
}