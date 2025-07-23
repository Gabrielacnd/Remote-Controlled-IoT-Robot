#include <SoftwareSerial.h> // Pentru comunicare serială cu ESP32

// Definirea motoarelor
#define FRONT_RIGHT_MOTOR 0
#define BACK_RIGHT_MOTOR 1
#define FRONT_LEFT_MOTOR 2
#define BACK_LEFT_MOTOR 3

#define FORWARD 1
#define BACKWARD -1
#define STOP 0

// Pinii pentru motoare
struct MOTOR_PINS {
  int pinIN1;
  int pinIN2;
};

MOTOR_PINS motorPins[] = {
  {2, 3},   // FRONT_RIGHT_MOTOR
  {4, 5},   // BACK_RIGHT_MOTOR
  {6, 7},   // FRONT_LEFT_MOTOR
  {8, 9}    // BACK_LEFT_MOTOR
};

// Comunicarea cu ESP32
SoftwareSerial ESPSerial(10, 11); // RX = 10, TX = 11 (poți schimba)

void rotateMotor(int motorNumber, int motorDirection) {
  if (motorDirection == FORWARD) {
    digitalWrite(motorPins[motorNumber].pinIN1, HIGH);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);
  } else if (motorDirection == BACKWARD) {
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, HIGH);
  } else {
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);
  }
}

void setUpPinModes() {
  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i].pinIN1, OUTPUT);
    pinMode(motorPins[i].pinIN2, OUTPUT);
    rotateMotor(i, STOP); // Toate motoarele oprite la început
  }
}

void processCarMovement(int command) {
  switch (command) {
    case 1: // UP
      rotateMotor(FRONT_RIGHT_MOTOR, FORWARD);
      rotateMotor(BACK_RIGHT_MOTOR, FORWARD);
      rotateMotor(FRONT_LEFT_MOTOR, FORWARD);
      rotateMotor(BACK_LEFT_MOTOR, FORWARD);
      break;
    case 2: // DOWN
      rotateMotor(FRONT_RIGHT_MOTOR, BACKWARD);
      rotateMotor(BACK_RIGHT_MOTOR, BACKWARD);
      rotateMotor(FRONT_LEFT_MOTOR, BACKWARD);
      rotateMotor(BACK_LEFT_MOTOR, BACKWARD);
      break;
    case 3: // LEFT
      rotateMotor(FRONT_RIGHT_MOTOR, FORWARD);
      rotateMotor(BACK_RIGHT_MOTOR, BACKWARD);
      rotateMotor(FRONT_LEFT_MOTOR, BACKWARD);
      rotateMotor(BACK_LEFT_MOTOR, FORWARD);
      break;
    case 4: // RIGHT
      rotateMotor(FRONT_RIGHT_MOTOR, BACKWARD);
      rotateMotor(BACK_RIGHT_MOTOR, FORWARD);
      rotateMotor(FRONT_LEFT_MOTOR, FORWARD);
      rotateMotor(BACK_LEFT_MOTOR, BACKWARD);
      break;
    case 0: // STOP
    default:
      for (int i = 0; i < 4; i++) rotateMotor(i, STOP);
      break;
  }
}

void setup() {
  ESPSerial.begin(9600); // Comunicarea cu ESP32
  Serial.begin(9600);    // Pentru debug
  setUpPinModes();
}

void loop() {
  if (ESPSerial.available()) {
    int command = ESPSerial.parseInt(); // Citește comanda de la ESP32
    processCarMovement(command);        // Execută comanda
    Serial.println(command);            // Pentru debug
  }
}
