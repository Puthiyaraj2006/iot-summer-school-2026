/*
 * Author      : Puthiyaraj P
 * Date        : 05-07-2026
 * Assignment  : Q27 - Relay Controlled AC Device Simulation
 * Description : Relay (LED) control using DHT sensor with hysteresis
 *               and manual override button.
 */

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22      

#define LED_PIN 8
#define BUTTON_PIN 3

DHT dht(DHTPIN, DHTTYPE);

bool relayState = false;
bool manualMode = false;

bool lastButtonState = HIGH;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);

  Serial.println("Relay Controlled AC Simulation Started");
}

void loop() {

  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read DHT sensor!");
    delay(1000);
    return;
  }

  // Manual Override Button
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {

    manualMode = !manualMode;

    relayState = !relayState;

    digitalWrite(LED_PIN, relayState);

    Serial.print("Manual Override -> Relay ");
    Serial.print(relayState ? "ON" : "OFF");
    Serial.print(" | Temp: ");
    Serial.print(temperature);
    Serial.println(" C");

    delay(300);
  }

  lastButtonState = buttonState;

  // Automatic Mode
  if (!manualMode) {

    if (temperature > 32.0 && !relayState) {

      relayState = true;
      digitalWrite(LED_PIN, HIGH);

      Serial.print("Relay ON | Temp: ");
      Serial.print(temperature);
      Serial.println(" C");
    }

    else if (temperature < 28.0 && relayState) {

      relayState = false;
      digitalWrite(LED_PIN, LOW);

      Serial.print("Relay OFF | Temp: ");
      Serial.print(temperature);
      Serial.println(" C");
    }
  }

  delay(500);
}
