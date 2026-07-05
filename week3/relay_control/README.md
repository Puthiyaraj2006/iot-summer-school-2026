# Q27 - Relay Controlled AC Device Simulation

## Author
Puthiyaraj

## Objective
Simulate an AC appliance using an LED as a relay indicator. The relay turns ON when the temperature exceeds 32°C and turns OFF when the temperature drops below 28°C. A push button provides manual override control.

## Components Used
- Arduino Uno
- DHT22 Sensor
- LED
- 220Ω Resistor
- Push Button
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 Data | D2 |
| LED | D8 |
| Push Button | D3 |

## Features
- Temperature above **32°C** turns the relay (LED) ON.
- Temperature below **28°C** turns the relay (LED) OFF.
- Implements hysteresis to prevent frequent switching.
- Manual override button toggles the relay state.
- Serial Monitor logs all relay state changes with temperature readings.

## Sample Output

```
Relay Controlled AC Simulation Started
Relay ON | Temp: 33.90 C
Relay OFF | Temp: 27.10 C
Manual Override -> Relay ON | Temp: 27.10 C
```
## Link
https://wokwi.com/projects/468692871938743297
