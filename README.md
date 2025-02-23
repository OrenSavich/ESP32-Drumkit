# Digi-Physi Drumkit & Metronome

## 🥁 Overview
The **Digi-Physi Drumkit** is an interactive digital percussion instrument combining a drumkit and metronome using an ESP32, piezo sensor, ultrasonic sensor, and speaker. The system detects drumming actions and gestures, producing sound effects and visual feedback.

🎥 **Demo Video**: [Watch here](https://www.youtube.com/watch?v=IpqU8gUZkZo)

## 🛠️ Features
- **Piezo Sensor**: Detects snare drum hits.
- **Ultrasonic Sensor**: Detects gestures to trigger cymbal sounds.
- **Metronome**: Provides rhythm with LED and speaker feedback.
- **Real-time Sound Effects**: Generates drum sounds dynamically.

## 🎯 How It Works
1. **Metronome Mode**:
   - LED blinks and speaker plays a beat at a set tempo.
2. **Drumming Interaction**:
   - **Snare Drum**: Hit detected via the piezo sensor.
   - **Cymbal Sound**: Triggered by proximity detection using the ultrasonic sensor.
3. **Adjustable Tempo**: Modify BPM as needed.

## 🔧 Hardware Requirements
- **ESP32**
- **Piezo Sensor**
- **HC-SR04 Ultrasonic Sensor**
- **Speaker**
- **LED Indicator**

## 📝 Circuit Connections
| Component            | Pin on ESP32 |
|---------------------|-------------|
| Piezo Sensor       | 34          |
| Ultrasonic Trigger | 16          |
| Ultrasonic Echo    | 17          |
| Speaker           | 25          |
| LED Indicator     | 18          |

## 🚀 Setup & Installation
1. **Install Arduino IDE** (if not already installed).
2. **Add Required Libraries** (if applicable).
3. **Upload the Code** to ESP32.
4. **Connect the Components** as per the table above.
5. **Power Up & Play!**

## 🎵 Sound Effects
- **Metronome Sound**: Provides consistent rhythm.
- **Drum Sounds**: Dynamic snare and cymbal effects.

## 📌 Authors
- **Oren Savich**
- **Rotem Peled**
