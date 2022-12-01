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
  // Runs 20 * 3 * 100 ms (6seconds), lights flash 60 times each
  for(int i = 0; i < 20; i++) {
    for (int j : leds) {
    digitalWrite(j, LOW);
    delay(50);
    digitalWrite(j, HIGH);
    delay(50);
  }
  }
}

void scroll() {
  // Mouse has special signal pin quadrature encoder.
  // Below hijacks the single pin encoder and the IRLed giving it stimulous.
  // Attempts to scroll for 6000ms (600 * 10). This is hit and miss if it works.
  // If this was a proper 2 pin quadrature encoder I could control it percisely,
  // but for my use case random works good enough!
  for(int i = 0; i< 600; i++) {
      digitalWrite(ioPin, HIGH);
      digitalWrite(irLed, LOW);
      delay(2);
      digitalWrite(irLed, HIGH);
      delay(3);
      digitalWrite(ioPin, LOW);
      delay(5);
  }
}

void loop() {
  int selector = random(1, 101);
  if (selector <= 20) {
    // 20% Chance of click
    click(random(1, 3) == 1 ? lmb : rmb);
  } else if (selector <= 40) {
    // 20% chance of scroll
    // Blue LED is turned on as an indicator of action
    digitalWrite(bLed, LOW);
    scroll();
    digitalWrite(bLed, HIGH);
  } else {
    // 50% chance of wiggle
    wiggle();
  }
  delay(10000);
}