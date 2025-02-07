
# 🚨 Alarm System Project 🚨

This project implements a simple alarm system using an ultrasonic sensor and a buzzer.

## 🚀 How it Works 🚀

The ultrasonic sensor measures the distance to an object. If the distance is less than a specified threshold, the buzzer will sound.

## 🛠️ Components 🛠️

*   Arduino board
*   Ultrasonic sensor (HC-SR04)
*   Buzzer

## ⚙️ Wiring ⚙️

*   Connect the ultrasonic sensor's VCC and GND to the Arduino's 5V and GND.
*   Connect the ultrasonic sensor's Trig pin to Arduino pin 9.
*   Connect the ultrasonic sensor's Echo pin to Arduino pin 10.
*   Connect the buzzer to Arduino pin 8.

## 💻 Usage 💻

1.  Upload the `Alarmsystem.ino` sketch to your Arduino board.
2.  Adjust the `THRESHOLD_DISTANCE_CM` constant in the code to set the desired detection range.

## 📝 Notes 📝

*   Ensure proper wiring for correct functionality.
*   Modify the buzzer frequency and duration in the code as needed.
