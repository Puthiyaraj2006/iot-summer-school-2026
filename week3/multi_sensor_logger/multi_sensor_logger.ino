/*
 * Author      : Puthiyaraj P
 * Date        : 05-07-2026
 * Assignment  : Q24 - Multi Sensor Data Logger
 * Description : Reads DHT22, LDR and HC-SR04 every 5 seconds.
 */

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define TRIG_PIN 9
#define ECHO_PIN 10

#define LDR_PIN A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int ldr = analogRead(LDR_PIN);
  int lightPercent = map(ldr, 0, 1023, 0, 100);

  String lightStatus;

  if (lightPercent > 70)
    lightStatus = "Bright";
  else
    lightStatus = "Dark";

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temp);
  Serial.print(" C | Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightStatus);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("==================");
  Serial.println();

  delay(5000);
}
