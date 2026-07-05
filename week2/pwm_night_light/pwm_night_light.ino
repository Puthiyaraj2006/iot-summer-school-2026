/*
 * Author: Puthiyaraj P
 * Date: 04-07-2026
 * Description: PWM Fading Night Light with Three Modes (Slow, Fast, SOS)
 * IIT Jammu Summer School 2026 - IoT Assignment Q17
 */

const int ledPin = 9;
const int buttonPin = 2;

int mode = 1;
int lastButtonState = HIGH;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("Mode : Slow Breathing");
}

void checkButton()
{
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH)
  {
    mode++;

    if (mode > 3)
      mode = 1;

    if (mode == 1)
      Serial.println("Mode : Slow Breathing");
    else if (mode == 2)
      Serial.println("Mode : Fast Pulse");
    else
      Serial.println("Mode : SOS");

    delay(200);   // debounce
  }

  lastButtonState = buttonState;
}

void loop()
{
  checkButton();

  if (mode == 1)
  {
    // Slow Breathing
    for (int i = 0; i <= 255; i++)
    {
      analogWrite(ledPin, i);
      delay(6);
      checkButton();
      if (mode != 1) return;
    }

    for (int i = 255; i >= 0; i--)
    {
      analogWrite(ledPin, i);
      delay(6);
      checkButton();
      if (mode != 1) return;
    }
  }

  else if (mode == 2)
  {
    // Fast Pulse
    for (int i = 0; i <= 255; i++)
    {
      analogWrite(ledPin, i);
      delay(1);
      checkButton();
      if (mode != 2) return;
    }

    for (int i = 255; i >= 0; i--)
    {
      analogWrite(ledPin, i);
      delay(1);
      checkButton();
      if (mode != 2) return;
    }
  }

  else if (mode == 3)
  {
    // SOS (... --- ...)
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
      checkButton();
      if (mode != 3) return;
    }

    for (int i = 0; i < 3; i++)
    {
      digitalWrite(ledPin, HIGH);
      delay(600);
      digitalWrite(ledPin, LOW);
      delay(200);
      checkButton();
      if (mode != 3) return;
    }

    for (int i = 0; i < 3; i++)
    {
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
      checkButton();
      if (mode != 3) return;
    }

    delay(1000);
  }
}
