#include <Servo.h>

Servo ESC;

#define ESC_PIN 9
#define STOP_PIN 8
#define ESC_OFF_MICROS 900

void setup(){
  // declare pin 9 to be an output:
  ESC.attach(ESC_PIN);
  ESC.writeMicroseconds(ESC_OFF_MICROS);
  pinMode(STOP_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

int escMicros = ESC_OFF_MICROS;

bool eStop = false;

void loop(){
  if (!digitalRead(STOP_PIN)) {
    eStop = true;
  }

  if (Serial.available()) {
    escMicros = Serial.parseInt();
    while (Serial.available()) Serial.read();
  }

  if (eStop) {
    ESC.writeMicroseconds(ESC_OFF_MICROS);
    Serial.println("Emergency Stopped.  Re-upload code to start again.");
  }
  else {
    ESC.writeMicroseconds(escMicros);
    Serial.print("ESC pulse width micros: ");
    Serial.println(escMicros);
  }
}