#include <Arduino.h>

// RGB Anodes
int rLed = 2;
int gLed = 3;
int bLed = 4;

// Right & Left mouse button
int rmb = 7;
int lmb = 8;

// Quadrature Encoder
int irLed = 13;
int ioPin = 12;
int irState = HIGH;

void click();
void wiggle();
void scroll();

void setup() {
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(irLed, OUTPUT);
  pinMode(ioPin, OUTPUT);
  // Anodes set to high to have LEDs off.
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, HIGH);
  // Set mouse buttons to low
  digitalWrite(rmb, LOW);
  digitalWrite(lmb, LOW);
  // Initial state of scroll
  digitalWrite(irLed, irState);
}

void click(int button) {
  // Simulate a mouse click, can be provided lmb or rmb
  digitalWrite(button, HIGH);
  delay(300);
  digitalWrite(button, LOW);
}

void wiggle() {
  // Flashes LEDs to stimulate mouse sensor, simulating movement.
  int leds[]={rLed, gLed, bLed};
  for (int i : leds) {
    digitalWrite(i, LOW);
    delay(50);
    digitalWrite(i, HIGH);
    delay(50);
  }
}

void scroll() {
  // Mouse has special signal pin quadrature encoder. Not sure how to spoof.
  // Tried hijacking the IRLED and the I/O pin, but couldn't get a phase that worked.
  /*
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(40);
    digitalWrite(13, HIGH);
    delay(60);
    digitalWrite(12, LOW);
    delay(100);
  */
}

void loop() {
  scroll();
}