# AI-Enabled IoT-Based Air Pollution Monitoring System

A smart, voice-interactive air pollution monitoring system that detects gas levels, temperature, and humidity in real time using Arduino sensors. The system classifies air quality into various health-impact levels and speaks out alerts using AI-powered voice synthesis. It also warns the user about gas leaks to prevent mishaps.

---

## 📌 Project Highlights
- 🔍 Real-time air quality monitoring using **MQ135** and **DHT11**
- 🗣️ AI voice alerts using **pyttsx3**
- 🔒 Gas leak detection for enhanced safety
- 🧠 Classification logic (Good, Moderate, Poor)
- 🔁 Serial communication between **Arduino Uno** and **Python**
- ⚙️ Easily extendable to AI/ML and cloud dashboard features

---

## ⚙️ Hardware Used
- Arduino Uno
- MQ135 Gas Sensor
- DHT11 Temperature & Humidity Sensor
- USB Cable
- Jumper Wires
- (Optional) 16x2 LCD Display

---

## 💻 Technologies & Libraries
- **Languages**: C++, Python  
- **Tools**: Arduino IDE, VS Code  
- **Python Libraries**:
  - `pyserial`
  - `pyttsx3`
  - (Optional) `scikit-learn` for future ML
  - (Optional) `pandas` for data logging

---

## 🧠 How It Works
1. Arduino reads values from MQ135 (gas) and DHT11 (temp + humidity).
2. Sends sensor data via serial to Python script.
3. Python:
   - Classifies the air quality (Good, Moderate, Poor, etc.).
   - Gives voice alerts for current air quality and gas leaks using `pyttsx3`.
4. (Optional) Log data or train ML models using historical readings.

---


