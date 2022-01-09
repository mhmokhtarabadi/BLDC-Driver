#include <Arduino.h>

const uint8_t APWM_PIN = 3;
const uint8_t BPWM_PIN = 5;
const uint8_t CPWM_PIN = 6;

const uint8_t Aen = DDB0;         // D8
const uint8_t Ben = DDB1;         // D9
const uint8_t Cen = DDB2;         // D10

const uint8_t Ahall = PCINT8;     // A0
const uint8_t Bhall = PCINT9;     // A1
const uint8_t Chall = PCINT10;    // A2

uint8_t s = 50;
const uint8_t d = 10;
uint8_t phase = 1;

ISR (PCINT1_vect) {
  if ((PINC & B00000101) && (phase == 6)) {
    phase = 1;
  }
  else if ((PINC & B00000001) && (phase == 1)) {
    phase = 2;
  }
  else if ((PINC & B00000011) && (phase == 2)) {
    phase = 3;
  }
  else if ((PINC & B00000010) && (phase == 3)) {
    phase = 4;
  }
  else if ((PINC & B00000110) && (phase == 4)) {
    phase = 5;
  }
  else if ((PINC & B00000100) && (phase == 5)) {
    phase = 6;
  }
}

void setup() {
  Serial.begin(9600);
  
  DDRB |= _BV(Aen) | _BV(Ben) | _BV(Cen);

  DDRC = B00000000;
  PORTC = B11111111;
  
  pinMode(APWM_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
  pinMode(CPWM_PIN, OUTPUT);

  PCICR |= _BV(PCIE1);
  PCMSK1 |= _BV(Ahall) | _BV(Bhall) | _BV(Chall);
  
}

void loop() {

  s = map(analogRead(A5), 0, 1023, 0, 255);

  switch (phase) {
    case 1:
      // state 1
      PORTB |= _BV(Aen) | _BV(Ben);
      PORTB &= ~_BV(Cen);
      analogWrite(APWM_PIN, s);
      analogWrite(BPWM_PIN, 0);
      break;

    case 2:
      // state 2
      PORTB |= _BV(Aen) | _BV(Cen);
      PORTB &= ~_BV(Ben);
      analogWrite(APWM_PIN, s);
      analogWrite(CPWM_PIN, 0);
      break;

    case 3:
      // state 3
      PORTB |= _BV(Ben) | _BV(Cen);
      PORTB &= ~_BV(Aen);
      analogWrite(BPWM_PIN, s);
      analogWrite(CPWM_PIN, 0);
      break;

    case 4:
      // state 4
      PORTB |= _BV(Ben) | _BV(Aen);
      PORTB &= ~_BV(Cen);
      analogWrite(BPWM_PIN, s);
      analogWrite(APWM_PIN, 0);
      break;

    case 5:
      // state 5
      PORTB |= _BV(Cen) | _BV(Aen);
      PORTB &= ~_BV(Ben);
      analogWrite(CPWM_PIN, s);
      analogWrite(APWM_PIN, 0);
      break;

    case 6:
      // state 6
      PORTB |= _BV(Cen) | _BV(Ben);
      PORTB &= ~_BV(Aen);
      analogWrite(CPWM_PIN, s);
      analogWrite(BPWM_PIN, 0);
      break;
  }

  Serial.println(phase);
  
}
