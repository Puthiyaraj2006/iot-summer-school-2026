/*
 * Author      : Puthiyaraj P
 * Date        : 05-07-2026
 * Assignment  : Q26 - DC Motor Speed Control
 */

const int potPin = A0;
const int dirButton = 2;
const int startButton = 3;

const int ENA = 5;   // PWM
const int IN1 = 8;
const int IN2 = 9;

bool direction = true;     // true = Forward
bool motorState = true;    // true = Running

bool lastDir = HIGH;
bool lastStart = HIGH;

void setup() {

  Serial.begin(9600);

  pinMode(dirButton, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.println("DC Motor Controller Started");
}

void loop() {

  // Read potentiometer
  int potValue = analogRead(potPin);

  // Convert to PWM
  int pwm = map(potValue, 0, 1023, 0, 255);

  // Direction button
  bool dirNow = digitalRead(dirButton);

  if (lastDir == HIGH && dirNow == LOW) {
    direction = !direction;
    delay(200);
  }

  lastDir = dirNow;

  // Start/Stop button
  bool startNow = digitalRead(startButton);

  if (lastStart == HIGH && startNow == LOW) {
    motorState = !motorState;
    delay(200);
  }

  lastStart = startNow;

  if (motorState) {

    analogWrite(ENA, pwm);

    if (direction) {

      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

    } else {

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }

  } else {

    analogWrite(ENA, 0);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  Serial.print("Direction: ");
  Serial.print(direction ? "Forward" : "Reverse");

  Serial.print(" | Speed: ");
  Serial.print(map(pwm, 0, 255, 0, 100));
  Serial.print("%");

  Serial.print(" | State: ");
  Serial.println(motorState ? "Running" : "Stopped");

  delay(500);
}
