# Q28 - Keypad + LCD Password Protected Access System

## Author
Puthiyaraj P

## Objective
Build a password-protected access system using a 4x4 keypad and a 16x2 LCD. The system validates a 4-digit PIN, grants or denies access, and locks for 10 seconds after three incorrect attempts.

## Components Used
- Arduino Uno
- 4x4 Membrane Keypad
- 16x2 I2C LCD
- Green LED
- Red LED
- Buzzer
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Keypad Rows | D9, D8, D7, D6 |
| Keypad Columns | D5, D4, D3, D2 |
| Green LED | D10 |
| Red LED | D11 |
| Buzzer | D12 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## Features
- Displays **ENTER PIN:** on LCD.
- Accepts a 4-digit PIN.
- Correct PIN displays **ACCESS GRANTED** and turns ON the green LED.
- Incorrect PIN displays **ACCESS DENIED**, turns ON the red LED, and activates the buzzer.
- Locks the system for 10 seconds after three incorrect attempts.
- Serial Monitor logs PIN validation and system status.

## Default PIN
1234

## Sample Serial Output

```
Password Access System Started

Entered PIN: 1234
ACCESS GRANTED

Entered PIN: 1111
ACCESS DENIED
Wrong Attempts: 1

Entered PIN: 2222
ACCESS DENIED
Wrong Attempts: 2

Entered PIN: 3333
ACCESS DENIED
Wrong Attempts: 3
SYSTEM LOCKED FOR 10 SECONDS
SYSTEM UNLOCKED
```
## Link
https://wokwi.com/projects/468694416935950337
