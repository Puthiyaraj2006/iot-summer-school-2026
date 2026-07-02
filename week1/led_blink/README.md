# LED Blink Project

## Project Title
LED Blink using Arduino Uno

## Hardware Required
- Arduino Uno
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

## Circuit Diagram Description
1. Connect the LED anode (+) to Arduino digital pin 13.
2. Connect a 220Ω resistor in series with the LED.
3. Connect the LED cathode (-) to GND.
4. Connect Arduino to the computer using a USB cable.

Circuit Connection:

Arduino Pin 13 ---> Resistor ---> LED ---> GND

## How to Upload Code

### Step 1
Open Arduino IDE.

### Step 2
Connect Arduino Uno to the computer using a USB cable.

### Step 3
Open the LED Blink sketch.

### Step 4
Select:
Tools → Board → Arduino Uno

### Step 5
Select the correct COM Port:
Tools → Port

### Step 6
Click the Verify button to compile the code.

### Step 7
Click the Upload button to upload the program to Arduino.

## Expected Output
- The LED connected to pin 13 turns ON.
- The LED turns OFF after a delay.
- The LED continuously blinks in a loop.

## Troubleshooting Tips

### 1. LED Not Blinking
Check whether the LED is connected with the correct polarity.

### 2. Upload Error
Ensure the correct board and COM port are selected in Arduino IDE.

### 3. Loose Connections
Verify all jumper wire and breadboard connections.

### 4. Power Issue
Check whether the Arduino is properly powered through the USB cable.
