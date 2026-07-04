const int buzzer = 8;

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(button1) == LOW) {
    tone(buzzer, 262);
  }

  else if (digitalRead(button2) == LOW) {
    tone(buzzer, 294);
  }

  else if (digitalRead(button3) == LOW) {
    tone(buzzer, 330);
  }

  else if (digitalRead(button4) == LOW) {
    tone(buzzer, 349);
  }

  else {
    noTone(buzzer);
  }

}
