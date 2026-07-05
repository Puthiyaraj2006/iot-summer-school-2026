/*
 * Author      : Puthiyaraj
 * Date        : 05-07-2026
 * Assignment  : Q28 - Keypad + LCD Display
 * Description : Password-protected access system using a 4x4 keypad,
 *               16x2 LCD, LEDs, and buzzer with 10-second lock after
 *               three incorrect PIN attempts.
 */
 #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- Keypad --------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// -------- LEDs & Buzzer --------
const int greenLED = 10;
const int redLED = 11;
const int buzzer = 12;

// -------- Password --------
String correctPIN = "1234";
String enteredPIN = "";

int wrongAttempts = 0;
bool locked = false;
unsigned long lockTime = 0;

void setup() {

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");
}

void loop() {

  // Lock for 10 seconds
  if (locked) {

    if (millis() - lockTime < 10000) {

      lcd.setCursor(0,1);
      lcd.print("LOCKED 10 SEC ");

      return;
    }

    locked = false;
    wrongAttempts = 0;

    lcd.clear();
    lcd.print("ENTER PIN:");
    enteredPIN = "";
  }

  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {

      enteredPIN += key;

      lcd.setCursor(enteredPIN.length()-1,1);
      lcd.print("*");
    }

    if (enteredPIN.length() == 4) {

      delay(300);

      if (enteredPIN == correctPIN) {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("GRANTED");

        digitalWrite(greenLED, HIGH);

        delay(3000);

        digitalWrite(greenLED, LOW);

        wrongAttempts = 0;
      }

      else {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("DENIED");

        digitalWrite(redLED, HIGH);

        tone(buzzer,1000,500);

        delay(1000);

        digitalWrite(redLED, LOW);

        wrongAttempts++;

        if (wrongAttempts >= 3) {

          locked = true;
          lockTime = millis();

          lcd.clear();
          lcd.print("SYSTEM");
          lcd.setCursor(0,1);
          lcd.print("LOCKED");
        }
      }

      enteredPIN = "";

      if (!locked) {

        lcd.clear();
        lcd.print("ENTER PIN:");
      }
    }
  }
}
