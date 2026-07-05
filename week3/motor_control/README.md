# Q26 - DC Motor Speed Control

## Author
Puthiyaraj P

## Objective
Control a DC motor using a motor driver. The potentiometer adjusts the motor speed, one push button changes the motor direction, and another push button starts or stops the motor.

## Components Used
- Arduino Uno
- L293D Motor Driver
- DC Motor
- Potentiometer (10kΩ)
- Push Button ×2
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Potentiometer | A0 |
| Direction Button | D2 |
| Start/Stop Button | D3 |
| L293D Enable (ENA) | D5 (PWM) |
| L293D IN1 | D8 |
| L293D IN2 | D9 |

## Features
- Potentiometer controls motor speed (0–255 PWM).
- Direction button switches the motor between Forward and Reverse.
- Start/Stop button turns the motor ON and OFF.
- Serial Monitor displays:
  - Direction
  - Speed (0–100%)
  - Motor State (Running/Stopped)

## Sample Output

```
Direction: Forward | Speed: 35% | State: Running
Direction: Reverse | Speed: 80% | State: Running
Direction: Reverse | Speed: 80% | State: Stopped
```
