/*
 * Author: Puthiyaraj P
 * Date: 04-07-2026
 * Description: Traffic Light Controller with Pedestrian Button and Serial Monitor Output
 * IIT Jammu Summer School 2026 - IoT Assignment Q14
 */

const int RED = 2;
const int YELLOW = 3;
const int GREEN = 4;
const int BUTTON = 7;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    Serial.print(millis());
    Serial.println(" ms : PEDESTRIAN - RED");

    delay(8000);
  }

  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED");

  delay(5000);

  if (digitalRead(BUTTON) == LOW) return;

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : YELLOW");

  delay(2000);

  if (digitalRead(BUTTON) == LOW) return;

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN");

  delay(4000);
}
