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
  // Anodes set to high to have LEDs off.
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, HIGH);
  // Set mouse buttons to low
  digitalWrite(rmb, LOW);
  digitalWrite(lmb, LOW);
  // Initial state of scroll
  digitalWrite(qEf, qEfState);
  digitalWrite(qEb, qEbState);
}

void click(int button) {
  // Simulate a mouse click, can be provided lmb or rmb
  digitalWrite(button, HIGH);
  delay(200);
  digitalWrite(button, LOW);
}

void wiggle() {
  // Flashes LEDs to stimulate mouse sensor, simulating movement.
  int leds[]={rLed, gLed, bLed};
  for (int i : leds) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(50);
  }
}

void scroll() {
  digitalWrite(qEf, !qEfState);
  digitalWrite(qEb, !qEbState);
  delay(100);
}

void loop() {
  
}