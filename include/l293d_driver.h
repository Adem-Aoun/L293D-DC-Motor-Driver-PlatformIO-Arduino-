#ifndef L293D_DRIVER_H
#define L293D_DRIVER_H

#include <Arduino.h>

typedef struct{
     int INP1;
     int INP2;
     int ENABLE12;
}Motor;


#ifdef __cplusplus
extern "C" {
#endif
//call this functions in setup();
void setup_motor(Motor *motor);

void cc_motor(Motor *motor,float speed);

void ccw_motor(Motor *motor,float speed);

void stop_motor(Motor *motor);

void brake_motor(Motor *motor);

#ifdef __cplusplus
}
#endif
#endif