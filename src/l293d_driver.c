#include "l293d_driver.h"

static inline int map_speed(float speed){
    if (speed < 0) speed =0;
    else if(speed > 100) speed=100;
    return (int)(speed*255.0/100.0);
}

void setup_motor(Motor *motor){
    if(!motor) return;
    pinMode(motor->INP1,OUTPUT);
    pinMode(motor->INP2,OUTPUT);
    pinMode(motor->ENABLE12,OUTPUT);

    digitalWrite(motor->INP1,0);
    digitalWrite(motor->INP2,0);
    analogWrite(motor->ENABLE12,0);

}

void cc_motor(Motor *motor,float speed){
    if(!motor) return;
    digitalWrite(motor->INP1,1);
    digitalWrite(motor->INP2,0);
    analogWrite(motor->ENABLE12,map_speed(speed));
}

void ccw_motor(Motor *motor,float speed){
    if(!motor) return;
    digitalWrite(motor->INP1,0);
    digitalWrite(motor->INP2,1);
    analogWrite(motor->ENABLE12,map_speed(speed));
}

void stop_motor(Motor *motor){
    if(!motor) return;
    analogWrite(motor->ENABLE12,0);
}

void brake_motor(Motor *motor){
    if(!motor) return;
    digitalWrite(motor->INP1,1);
    digitalWrite(motor->INP2,1);
    analogWrite(motor->ENABLE12,255);
}
