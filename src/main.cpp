#include <Arduino.h>

// RGB Anodes
int rLed = 2;
int gLed = 3;
int bLed = 4;

// Right & Left mouse button
int rmb = 7;
int lmb = 8;

// Quadrature Encoder Front & Back
int qEf = 13;
int qEb = 12;
int qEfState = HIGH;
int qEbState = LOW;

void click();
void wiggle();
void scroll();

void setup() {
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(qEf, OUTPUT);
  pinMode(qEb, OUTPUT);
  // Initial state of scroll
  digitalWrite(qEf, qEfState);
  digitalWrite(qEb, qEbState);
  // Anodes set to high to have LEDs off.
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
}