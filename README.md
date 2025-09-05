# L293D DC Motor Driver (PlatformIO + Arduino)

A **DC motor driver** using the **L293D H-Bridge** with PlatformIO.
This project provides a driver library and example code to control a DC motor with PWM speed control and limit switch support.

---

## 📂 Project Structure

```
.
├── include/          # Header files (driver interface)
│   └── l293d_driver.h
├── lib/              # External libraries 
├── src/              # Source code
│   ├── l293d_driver.c
│   └── main.cpp
├── test/             # Tests 
└── platformio.ini    # PlatformIO configuration
```

---

## ⚙️ Features

* Control DC motor **clockwise (CW)** and **counter-clockwise (CCW)**.
* **Variable speed** control (0–100% speed).
* **Brake** and **Stop** modes.
* Easy-to-use `Motor` struct for pin mapping.
* Limit switch example for safety.

---

## 🚀 Getting Started

### 1. Requirements

* [PlatformIO](https://platformio.org/)
* Arduino-compatible board (tested on **Arduino Nano**, works on ESP32, etc.)
* L293D motor driver IC
* DC motor + power supply

### 2. Wiring Example

| Arduino Pin | L293D Pin | Description   |
| ----------- | --------- | ------------- |
| 4           | IN1       | Motor input 1 |
| 5           | IN2       | Motor input 2 |
| 3 (PWM)     | EN1/2     | PWM     |
| 6           | Switch    | Limit switch  |

### 3. Installation

Clone this repo and open with PlatformIO:

```bash
git clone https://github.com/YOUR_USERNAME/dc_motor_driver_l293d.git
cd dc_motor_driver_l293d
```

Build & upload:

```bash
pio run --target upload
```

---

## 📖 Example Usage

```cpp
#include <Arduino.h>
#include "l293d_driver.h"

// Motor pins
Motor motor1 = {4, 5, 3};

// Limit switch pin
#define LIMIT_SWITCH 6
byte LIMIT_SWITCH_STATE;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting .......");
  setup_motor(&motor1);
  pinMode(LIMIT_SWITCH, INPUT_PULLUP);
}

void loop() {
  LIMIT_SWITCH_STATE = digitalRead(LIMIT_SWITCH);
  Serial.print("SWITCH = ");
  Serial.println(LIMIT_SWITCH_STATE);

  // Run motor clockwise at 30% speed
  cc_motor(&motor1, 30);

  // If switch is pressed -> brake motor
  if (!LIMIT_SWITCH_STATE) {
    brake_motor(&motor1);
  }
}
```

---

## 🔧 API Reference

### Struct

```c
typedef struct {
    int INP1;
    int INP2;
    int ENABLE12;
} Motor;
```

### Functions

* `void setup_motor(Motor *motor);` → Initialize motor pins.
* `void cc_motor(Motor *motor, float speed);` → Run motor clockwise (`speed` = 0–100).
* `void ccw_motor(Motor *motor, float speed);` → Run motor counter-clockwise (`speed` = 0–100).
* `void stop_motor(Motor *motor);` → Stop motor (no PWM).
* `void brake_motor(Motor *motor);` → Hard brake motor.

---

## 👤 Author

Developed by [Adem aoun](https://github.com/Adem-Aoun)
