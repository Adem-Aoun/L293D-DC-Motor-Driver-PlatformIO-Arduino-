#include <Arduino.h>
#include "l293d_driver.h"

Motor motor1 = {4,5,3};
#define LIMIT_SWITCH 6

byte LIMIT_SWITCH_STATE ;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting .......");
  setup_motor(&motor1);
  pinMode(LIMIT_SWITCH,INPUT_PULLUP);
}

void loop() {
  LIMIT_SWITCH_STATE = digitalRead(LIMIT_SWITCH);
  Serial.print("SWITCH = ");
  Serial.println(LIMIT_SWITCH_STATE);

  cc_motor(&motor1,30);

  if (!LIMIT_SWITCH_STATE){
    brake_motor(&motor1);
  }
}

