#include "l293d_driver.h"

static inline int map_speed(float speed){
    if (speed < 0) speed =0;
    if(speed > 100) speed=100;
    return (int)(speed*255.0/100.0);
}

void setup_motor(Motor *motor){
    pinMode(motor->INP1,OUTPUT);
    pinMode(motor->INP2,OUTPUT);
    pinMode(motor->ENABLE12,OUTPUT);

}

void cc_motor(Motor *motor,float speed){
    digitalWrite(motor->INP1,1);
    digitalWrite(motor->INP2,0);
    analogWrite(motor->ENABLE12,map_speed(speed));
}

void ccw_motor(Motor *motor,float speed){
    digitalWrite(motor->INP1,0);
    digitalWrite(motor->INP2,1);
    analogWrite(motor->ENABLE12,map_speed(speed));
}

void stop_motor(Motor *motor){
    digitalWrite(motor->ENABLE12,0);
}

void brake_motor(Motor *motor){
    digitalWrite(motor->INP1,1);
    digitalWrite(motor->INP2,1);
    analogWrite(motor->ENABLE12,255);
}