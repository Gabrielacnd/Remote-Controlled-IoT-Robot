# Remote-Controlled IoT Robot

This project consists of a remotely controlled robot, built using **ESP32** and **Arduino** platforms that communicate via UART. The purpose is to demonstrate wireless control over an autonomous robot, with potential expansion for IoT applications.

## Architecture

- **ESP32**: Main controller that receives commands from the user (via Bluetooth, Serial, etc.) and forwards them.
- **Arduino**: Interprets commands from the ESP32 and controls:
  - Motors (via L298N driver)
  - Sensors (ultrasonic, IR)
- **Communication**: UART between ESP32 and Arduino

## File Structure

| File               | Description                                                |
|--------------------|------------------------------------------------------------|
| `control.ino`      | ESP32 code – reads commands and sends them via UART        |
| `RobotArduino.ino` | Arduino code – interprets commands and controls the robot  |
| `README.md`        | This file                                                  |

## Hardware Connections

- ESP32 `TX` → Arduino `RX`  
- ESP32 `RX` ← Arduino `TX`  
- Shared GND  
- Motors connected via L298N  
- Sensors connected to Arduino digital pins

## How to Run

1. Upload `RobotArduino.ino` to the Arduino board (Uno/Nano)
2. Upload `control.ino` to the ESP32
3. Open the Serial Monitor (or a mobile Bluetooth app)
4. Send commands (`F`, `B`, `L`, `R`, `S`) to control the robot

## Available Commands

| Command | Action        |
|---------|---------------|
| `F`     | Move forward  |
| `B`     | Move backward |
| `L`     | Turn left     |
| `R`     | Turn right    |
| `S`     | Stop          |
