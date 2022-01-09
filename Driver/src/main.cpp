#include <Arduino.h>

const uint8_t APWM_PIN = 3;
const uint8_t BPWM_PIN = 5;
const uint8_t CPWM_PIN = 6;

const uint8_t Aen = DDB0;         // D8
const uint8_t Ben = DDB1;         // D9
const uint8_t Cen = DDB2;         // D10

const uint8_t s = 50;
const uint8_t d = 10;

void setup() {
  DDRB = _BV(Aen) | _BV(Ben) | _BV(Cen);

  pinMode(APWM_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
  pinMode(CPWM_PIN, OUTPUT);
  
}

void loop() {
  // state 1
  PORTB |= _BV(Aen) | _BV(Ben);
  PORTB &= ~_BV(Cen);
  analogWrite(APWM_PIN, s);
  analogWrite(BPWM_PIN, 0);
  delay(d);

  // state 2
  PORTB |= _BV(Aen) | _BV(Cen);
  PORTB &= ~_BV(Ben);
  analogWrite(APWM_PIN, s);
  analogWrite(CPWM_PIN, 0);
  delay(d);

  // state 3
  PORTB |= _BV(Ben) | _BV(Cen);
  PORTB &= ~_BV(Aen);
  analogWrite(BPWM_PIN, s);
  analogWrite(CPWM_PIN, 0);
  delay(d);

  // state 4
  PORTB |= _BV(Ben) | _BV(Aen);
  PORTB &= ~_BV(Cen);
  analogWrite(BPWM_PIN, s);
  analogWrite(APWM_PIN, 0);
  delay(d);

  // state 5
  PORTB |= _BV(Cen) | _BV(Aen);
  PORTB &= ~_BV(Ben);
  analogWrite(CPWM_PIN, s);
  analogWrite(APWM_PIN, 0);
  delay(d);

  // state 6
  PORTB |= _BV(Cen) | _BV(Ben);
  PORTB &= ~_BV(Aen);
  analogWrite(CPWM_PIN, s);
  analogWrite(BPWM_PIN, 0);
  delay(d);
}