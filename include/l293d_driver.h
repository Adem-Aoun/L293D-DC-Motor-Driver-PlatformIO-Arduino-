/**
 * @file l293d_driver.h
 * @brief Simple driver for controlling DC motors using L293D.
 */

#ifndef L293D_DRIVER_H
#define L293D_DRIVER_H

#include <Arduino.h>

/**
 * @brief Structure representing a motor connected to L293D.
 */
typedef struct{
    int INP1;      ///< Input pin 1
    int INP2;      ///< Input pin 2
    int ENABLE12;  ///< Enable (PWM) pin
} Motor;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize motor pins and set safe default state (stopped).
 * @param motor Pointer to Motor structure
 */
void setup_motor(Motor *motor);

/**
 * @brief Rotate motor clockwise.
 * @param motor Pointer to Motor structure
 * @param speed Speed percentage (0–100)
 */
void cc_motor(Motor *motor, float speed);

/**
 * @brief Rotate motor counter-clockwise.
 * @param motor Pointer to Motor structure
 * @param speed Speed percentage (0–100)
 */
void ccw_motor(Motor *motor, float speed);

/**
 * @brief Stop motor (coast).
 * @param motor Pointer to Motor structure
 */
void stop_motor(Motor *motor);

/**
 * @brief Actively brake the motor.
 * @param motor Pointer to Motor structure
 */
void brake_motor(Motor *motor);

#ifdef __cplusplus
}
#endif

#endif
