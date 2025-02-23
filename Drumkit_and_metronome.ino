/*
  Digi-Physi Musical Instrument
 
  Drumkit and Metronome

  This sketch combines a drum kit and a metronome using various sensors and outputs.
  We drew inspiration from a drum kit setup, featuring components akin to a snare and cymbal.
  The piezo sensor mimics the response of hitting a drum surface,
  while the ultrasonic sensor functions akin to detecting a hand gesture or object proximity, similar to striking a cymbal.
  By combining these sensors with a metronome, we created a dynamic percussion experience, suitable for experimentation and exploration in electronic music projects.
  
  The circuit:
  * Piezo sensor attached to pin 34
  * Ultrasonic sensor with trigger pin 16 and echo pin 17
  * LED attached to pin 18
  * Speaker attached to pin 25

  Video link: https://www.youtube.com/watch?v=IpqU8gUZkZo

  Created By:
  Oren Savich 207610668
  Rotem Peled 206463572
*/

#include <Arduino.h> // Include standard Arduino library

const int piezoPin = 34;
const int triggerPin = 16;
const int echoPin = 17;
const int speakerPin = 25;
const int ledPin = 18; // LED pin

const int snareSound[] = {1000, 1500, 1200}; // Array for snare sound (frequency in Hz)
const int cymbalSound[] = {1500, 2000, 1800}; // Array for cymbal sound (frequency in Hz)
const int metronomeTempo = 120; // Beats per minute (adjust as needed)
const int metronomeSound = 1000; // Metronome sound frequency in Hz

int snareSize = sizeof(snareSound) / sizeof(snareSound[0]); // Get size of snareSound array
int cymbalSize = sizeof(cymbalSound) / sizeof(cymbalSound[0]); // Get size of cymbalSound array

void setup() {
  pinMode(speakerPin, OUTPUT); // Set speaker pin as output
  pinMode(triggerPin, OUTPUT); // Set trigger pin for ultrasonic sensor as output
  pinMode(echoPin, INPUT); // Set echo pin for ultrasonic sensor as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  // Metronome
  unsigned long interval = 60000 / metronomeTempo; // Calculate interval in milliseconds
  static unsigned long previousMillis = 0; // Variable to store the last time LED was updated

  unsigned long currentMillis = millis(); // Get the current time
  if (currentMillis - previousMillis >= interval) { // If it's time for the next beat
    previousMillis = currentMillis; // Save the last time the LED blinked
    digitalWrite(ledPin, HIGH); // Turn on the LED
    tone(speakerPin, metronomeSound, 10); // Play metronome sound
    delay(10); // Wait a little bit to ensure LED and sound are noticeable
    digitalWrite(ledPin, LOW); // Turn off the LED
    noTone(speakerPin); // Stop metronome sound
  }

  // Check for piezo sensor hit
  if (analogRead(piezoPin) > 500) { // Adjust threshold value based on your sensor sensitivity
    playDrum(snareSound, snareSize); // Play snare sound
  }

  // Check for ultrasonic sensor signal
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); // Trigger pulse for ultrasonic sensor
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // Duration of trigger pulse
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH); // Measure duration of echo pulse

  // Check distance based on echo pulse duration (adjust threshold based on sensor)
  if (duration > 0 && duration < 1000) { // Adjust distance threshold
    playDrum(cymbalSound, cymbalSize); // Play cymbal sound if object detected
  }

  delay(10); // Add a small delay to avoid overloading the loop
}

void playDrum(const int sound[], int size) {
  for (int i = 0; i < size; i++) {
    tone(speakerPin, sound[i], 10); // Play sound at specific frequency for 10ms
    delay(10); // Short delay between frequency changes
  }
  noTone(speakerPin); // Stop sound after playing the sequence
}
