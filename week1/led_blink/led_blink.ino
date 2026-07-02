/*
Author: Puthiyaraj P
Date: 02-07-2026
Description: LED blink with potentiometer speed control and serial blink counter
*/
int count = 0;
int potPin = A0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin);
  int delayTime = map(sensorValue, 0, 1023, 100, 1000);

  digitalWrite(13, HIGH);
  delay(delayTime);
  digitalWrite(13, LOW);
  delay(delayTime);

  count++;
  Serial.print("Blink count: ");
  Serial.println(count);
}
// Fixed issue #2
