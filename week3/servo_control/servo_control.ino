/*
 * Author      : Puthiyaraj P
 * Date        : 05-07-2026
 * Assignment  : Q25 - Servo Motor Sweep
 * Description : Pot controls servo angle. Button performs full sweep.
 */

#include <Servo.h>

Servo servo;

#define POT_PIN A0
#define BUTTON_PIN 2
#define SERVO_PIN 9

void setup() {

  Serial.begin(9600);

  servo.attach(SERVO_PIN);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

  int potValue = analogRead(POT_PIN);

  int angle = map(potValue, 0, 1023, 0, 180);

  servo.write(angle);

  Serial.print("Servo Angle: ");
  Serial.println(angle);

  if (digitalRead(BUTTON_PIN) == LOW) {

    // 0 -> 180
    for(int i=0;i<=180;i++){
      servo.write(i);
      delay(10);
    }

    //180 ->0
    for(int i=180;i>=0;i--){
      servo.write(i);
      delay(10);
    }
  }

  delay(200);
}
