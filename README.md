# Advanced_train_coach
A real-time IoT-based train coach system built using ESP32 to monitor passenger safety and environment inside the coach. It uses sensors to detect fire, gas, intrusions, and more — and displays the data on a web server or mobile app. Can trigger alerts locally and remotely.
 Advanced Smart Train Coach System using NodeMCU 🚆
This project demonstrates an IoT-based intelligent train coach system using NodeMCU (ESP8266) to enhance passenger safety, comfort, and automation. The system integrates display, sensors, audio, and control mechanisms to create a smart and interactive train coach experience.

🔧 Key Components Used:
Component	                     Purpose
NodeMCU ESP8266	         Main microcontroller for logic, control, and communication
LCD Display (16x2)	     Displays train status or welcome messages
IR Sensor	Detects passenger presence (e.g., auto door/audio trigger)
SG90 Servo Motor	      Controls miniature door or seat demo (e.g., auto-open on detection)
DFPlayer Mini MP3	      Plays pre-recorded voice messages/audio announcements
Speaker	                Connected to DFPlayer to output sound
Wireless Charging Module	Demonstrates phone charging in modern coaches
Train Model	Physical train body to demonstrate placement and working

📲 How It Works:

When the IR sensor detects a person, the system:
Displays a message on the LCD
Plays a welcome message using DFPlayer Mini + speaker
Opens a door or demo gate using the SG90 servo
The wireless charging module powers devices when placed near the coach seat area.
System is low-power, compact, and suitable for smart metro/train coach automation.

🌐 Features:

Contactless welcome interaction
Real-time LCD updates
Voice announcements for passengers
Auto door control simulation
Wireless charging integration

📁 Repository Includes:

✅ Arduino Code (.ino)
✅ Circuit Diagram
✅ Wiring Instructions
✅ Audio File Setup Guide (for DFPlayer)
✅ README.md with details

💡 Applications:

Smart Indian Railways Coaches
Metro Coach Automation
Public Transport Technology Demo
Embedded System Educational Projects

Skills Demonstrated:

Embedded C programming
Sensor interfacing
Servo & audio control
Real-time display integration
IoT hardware integration
Power electronics (wireless charging demo)
