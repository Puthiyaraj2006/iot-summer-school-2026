/*
 * Author      : Puthiyaraj P
 * Date        : 05-07-2026
 * Assignment  : Q23 - Smart Street Light
 * Description : Smart Street Light using LDR and PIR sensor.
 */

#define LDR_PIN A0
#define PIR_PIN 2
#define LED_PIN 9

const int THRESHOLD = 500;

unsigned long motionStart = 0;
bool ledFull = false;

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Smart Street Light Started");
}

void loop() {

  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  unsigned long sec = millis() / 1000;

  int hh = sec / 3600;
  int mm = (sec % 3600) / 60;
  int ss = sec % 60;

  // DAY
  if (light < THRESHOLD) {

    analogWrite(LED_PIN, 0);

    printTime(hh, mm, ss);
    Serial.println(" EVENT: Daylight detected - LED OFF");

    delay(1000);
    return;
  }

  // NIGHT
 if (motion == HIGH && !ledFull) {

  analogWrite(LED_PIN, 255);

  motionStart = millis();
  ledFull = true;

  printTime(hh, mm, ss);
  Serial.println(" EVENT: Motion detected - LED FULL");
}

  if (ledFull) {

    if (millis() - motionStart >= 30000) {

      analogWrite(LED_PIN, 51);

      printTime(hh, mm, ss);
      Serial.println(" EVENT: No motion - LED DIM (20%)");

      ledFull = false;
      
    }

  } else {

    analogWrite(LED_PIN, 51);
  }

  delay(200);
}

void printTime(int h, int m, int s) {

  Serial.print("[");

  if (h < 10) Serial.print("0");
  Serial.print(h);
  Serial.print(":");

  if (m < 10) Serial.print("0");
  Serial.print(m);
  Serial.print(":");

  if (s < 10) Serial.print("0");
  Serial.print(s);

  Serial.print("]");
}
