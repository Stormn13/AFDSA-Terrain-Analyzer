# AFDSA-Terrain-Analyzer
Autonomous mobile robot for terrain suitability analysis using sensor fusion (IMU + environmental data) and on-device scoring (DSS) for precision equipment deployment.

# 🚗 Autonomous Field Deployment Suitability Analyzer (AFDSA)

A mobile robotic system designed to evaluate terrain suitability for precision equipment deployment using onboard sensor fusion and real-time scoring.

---

## 📌 Overview

The **AFDSA** is an embedded robotic platform that autonomously navigates a defined area, collects environmental and stability data, and computes a **Deployment Suitability Score (DSS)** for each location.

Unlike traditional methods, this system:

* Requires **no cloud processing**
* Runs entirely **on-device**
* Provides **objective, repeatable terrain analysis**

📄 Based on our practicum report: 

---

## 🎯 Problem Statement

Manual terrain assessment is:

* Time-consuming
* Inconsistent
* Sparse in data coverage

AFDSA solves this by:

* Automating data collection
* Standardizing evaluation using DSS
* Providing actionable classification (Suitable / Marginal / Unsuitable)

---

## ⚙️ System Architecture

The system consists of four main subsystems:

* **Sensing**

  * MPU6050 (IMU)
  * DHT22 (Temperature & Humidity)

* **Navigation**

  * 4WD Chassis
  * HC-SR04 (Obstacle detection)
  * L298N Motor Driver

* **Processing**

  * ESP32 / Arduino Mega

* **Output**

  * Serial communication (UART)

---

## 🧪 Methodology

At each grid point:

1. Robot stops
2. Collects sensor data (3-second window)
3. Computes stability parameters:

   * Vibration (RMS)
   * Surface Tilt
   * Temperature Drift
   * Humidity Variability
4. Calculates DSS
5. Classifies terrain

---

## 📊 Deployment Suitability Score (DSS)

The DSS is computed as a weighted combination:

* Vibration → 35%
* Tilt → 30%
* Temperature Drift → 20%
* Humidity Variability → 15%

### Classification:

| DSS Range | Classification | Meaning             |
| --------- | -------------- | ------------------- |
| ≥ 7.0     | Suitable       | Safe for deployment |
| 4.0–6.9   | Marginal       | Use with caution    |
| < 4.0     | Unsuitable     | Avoid deployment    |

---

## 📈 Sample Output

| Point | DSS | Classification |
| ----- | --- | -------------- |
| P1    | 8.6 | Suitable       |
| P2    | 6.2 | Marginal       |
| P3    | 3.9 | Unsuitable     |

---

## 🚀 Features

* ✅ Fully autonomous grid navigation
* ✅ On-device sensor fusion (no cloud)
* ✅ Real-time scoring system
* ✅ Low-cost hardware design
* ✅ Modular firmware

---

## 🔌 Hardware Requirements

* ESP32 / Arduino Mega
* MPU6050 IMU
* DHT22 Sensor
* HC-SR04 Ultrasonic Sensor
* L298N Motor Driver
* 4 DC Motors + Chassis
* Battery Pack

---

## 💻 Software & Tools

* Arduino IDE / PlatformIO
* Wire.h
* MPU6050 Library
* DHT Sensor Library
* NewPing

---

## 📂 Project Structure

```
AFDSA/
│── firmware/
│   ├── sensors/
│   ├── dss/
│   ├── navigation/
│   └── main.ino
│
│── hardware/
│   ├── wiring_diagram.png
│   └── block_diagram.png
│
│── docs/
│   └── AFDSA_Report.pdf
│
│── data/
│   └── sample_outputs.csv
│
│── README.md
```

---

## 🔮 Future Improvements

* 🌱 Soil moisture sensing
* 📡 Wireless data transmission (Wi-Fi/Bluetooth)
* 📍 GPS-based mapping
* 🤖 Machine learning-based classification
* 🧭 SLAM navigation

---

## 👨‍💻 Contributors

* Miraan Vahie
* Piyush Gupta
* Akshat Sharma

---

## 📜 License

This project is for academic and research purposes.

---

## 💡 Why This Matters

This project shows how **low-cost embedded systems + robotics** can replace manual, subjective field decisions with **data-driven automation**.

---
