#include <Arduino.h>

const int APWM_PIN = 3;
const int BPWM_PIN = 5;
const int CPWM_PIN = 6;

const int Aen = 8;
const int Ben = 9;
const int Cen = 10;

const int s = 50;
const int d = 1;

void setup() {
  Serial.begin(9600);
  pinMode(APWM_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
  pinMode(CPWM_PIN, OUTPUT);
  pinMode(Aen, OUTPUT);
  pinMode(Ben, OUTPUT);
  pinMode(Cen, OUTPUT);
}

void loop() {
  // state 1
  Serial.println("state 1");
  digitalWrite(Aen, HIGH);
  digitalWrite(Ben, HIGH);
  digitalWrite(Cen, LOW);
  analogWrite(APWM_PIN, s);
  analogWrite(BPWM_PIN, 0);
  delay(d);

  // state 2
  Serial.println("state 2");
  digitalWrite(Aen, HIGH);
  digitalWrite(Ben, LOW);
  digitalWrite(Cen, HIGH);
  analogWrite(APWM_PIN, s);
  analogWrite(CPWM_PIN, 0);
  delay(d);

  // state 3
  Serial.println("state 3");
  digitalWrite(Aen, LOW);
  digitalWrite(Ben, HIGH);
  digitalWrite(Cen, HIGH);
  analogWrite(BPWM_PIN, s);
  analogWrite(CPWM_PIN, 0);
  delay(d);

  // state 4
  Serial.println("state 4");
  digitalWrite(Aen, HIGH);
  digitalWrite(Ben, HIGH);
  digitalWrite(Cen, LOW);
  analogWrite(BPWM_PIN, s);
  analogWrite(APWM_PIN, 0);
  delay(d);

  // state 5
  Serial.println("state 5");
  digitalWrite(Aen, HIGH);
  digitalWrite(Ben, LOW);
  digitalWrite(Cen, HIGH);
  analogWrite(CPWM_PIN, s);
  analogWrite(APWM_PIN, 0);
  delay(d);

  // state 6
  Serial.println("state 6");
  digitalWrite(Aen, LOW);
  digitalWrite(Ben, HIGH);
  digitalWrite(Cen, HIGH);
  analogWrite(CPWM_PIN, s);
  analogWrite(BPWM_PIN, 0);
  delay(d);
}