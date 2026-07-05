/*
 * Author: Puthiyaraj P
 * Date: 04-07-2026
 * Description: Serial Command Interface for Built-in LED Control
 * IIT Jammu Summer School 2026 - IoT Assignment Q16
 */

int blinkCounter = 0;
bool ledState = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Serial Command Interface Ready");
}

void loop()
{
  if (Serial.available() > 0)
  {
    String command = Serial.readString();
    command.trim();

    if (command == "LED_ON")
    {
      digitalWrite(LED_BUILTIN, HIGH);
      ledState = true;
      Serial.println("LED Turned ON");
    }
    else if (command == "LED_OFF")
    {
      digitalWrite(LED_BUILTIN, LOW);
      ledState = false;
      Serial.println("LED Turned OFF");
    }
    else if (command == "STATUS")
    {
      if (ledState)
      {
        Serial.println("LED State : ON");
      }
      else
      {
        Serial.println("LED State : OFF");
      }

      Serial.print("Blink Count : ");
      Serial.println(blinkCounter);
    }
    else if (command == "RESET")
    {
      blinkCounter = 0;
      Serial.println("Blink Counter Reset");
    }
    else if (command.startsWith("BLINK_"))
    {
      int times = command.substring(6).toInt();

      if (times >= 1 && times <= 9)
      {
        for (int i = 0; i < times; i++)
        {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
        }

        blinkCounter += times;
        ledState = false;

        Serial.print("LED Blinked ");
        Serial.print(times);
        Serial.println(" Times");
      }
      else
      {
        Serial.println("ERROR: Blink value must be between 1 and 9");
      }
    }
    else
    {
      Serial.println("ERROR: Unknown command");
    }
  }
}
