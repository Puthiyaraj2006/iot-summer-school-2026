/*
 * Author      : Puthiyaraj P
 * Date        : 05-07-2026
 * Assignment  : Q22 - Ultrasonic Parking Sensor
 * Description : Measures distance using HC-SR04 sensor and
 *               controls LEDs and buzzer based on distance.
 */

#define TRIG_PIN 9
#define ECHO_PIN 10

#define YELLOW_LED 6
#define RED_LED 7
#define BUZZER 8

long duration;
float distance;

unsigned long previousMillis = 0;
bool buzzerState = false;
bool flashState = false;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("Ultrasonic Parking Sensor");
}

void loop() {

  // Trigger ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  // Assignment Formula
  distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // > 50 cm
  if (distance > 50) {

    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.println("SAFE");
  }

  // 20 - 50 cm
  else if (distance > 20) {

    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      buzzerState = !buzzerState;
      digitalWrite(BUZZER, buzzerState);
    }

    Serial.println("CAUTION");
  }

  // 10 - 20 cm
  else if (distance > 10) {

    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    if (currentMillis - previousMillis >= 200) {
      previousMillis = currentMillis;
      buzzerState = !buzzerState;
      digitalWrite(BUZZER, buzzerState);
    }

    Serial.println("WARNING");
  }

  // < 10 cm
  else {

    if (currentMillis - previousMillis >= 100) {
      previousMillis = currentMillis;

      flashState = !flashState;

      digitalWrite(YELLOW_LED, flashState);
      digitalWrite(RED_LED, flashState);
    }

    digitalWrite(BUZZER, HIGH);

    Serial.println("STOP");
  }

  delay(50);
}
