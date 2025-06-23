📡 Deauth Detector using ESP32 TTGO T-Display

*Developed by:* Zahir Lehri  
*Purpose:* Detect Wi-Fi deauthentication (DoS) attacks using an ESP32 in promiscuous mode.

> ⚠ For educational and authorized security auditing use only.

---

## 🔍 Overview

The Deauth Detector for ESP32 TTGO T-Display is a compact security monitoring tool that detects Wi-Fi deauthentication (DoS) attacks by listening to wireless traffic in promiscuous mode. If a deauthentication frame is detected, it instantly alerts the user via the onboard TFT screen and logs the event to the serial monitor. This project is perfect for ethical hackers, cybersecurity students, and network auditors to identify potential denial-of-service threats in Wi-Fi networks.

---

## 🛠 Hardware Required

- [TTGO T-Display ESP32 Board](https://www.lilygo.cc/products/t-display)
- Micro USB cable
- Computer with Arduino IDE or PlatformIO installed

---

## 📦 Software Requirements

You will need the *Arduino IDE* (or [PlatformIO](https://platformio.org/)) and the *ESP32 board support package* installed.

### 🧰 Required Arduino Libraries

Ensure you have the following libraries installed in the Arduino IDE:

cpp
#include <WiFi.h>       // ESP32 WiFi library
#include <TFT_eSPI.h>   // TFT display library
#include <esp_wifi.h>   // ESP32 low-level Wi-Fi functions


## 📸 Screenshots

### 🖥 TFT Display when Deauth Attack is Detected
<img src="https://github.com/user-attachments/assets/b3f108e1-6662-4f7e-98f0-07031b16c7ea" alt="TFT Display 2" width="300"/>
<img src="https://github.com/user-attachments/assets/ce226e8b-dc4d-4cda-b461-21ffe419238e" alt="TFT Display 2" width="300"/>
<img src="https://github.com/user-attachments/assets/664911d4-f0ee-4522-9952-7142720ee2d5" alt="TFT Display 1" width="300"/>



