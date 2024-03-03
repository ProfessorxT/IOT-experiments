/*
Experiment No. : 03
Statement : Make a light intensity meter that represent light intensity on 5 LEDs, such that all LEDs
would glow for maximum light, no LED would glow for dark condition, and likewise for
in between light intensities.
Date of Exp. : xx/xx/xxxx
Author : Tushar Rawte (A-06)
*/

const int ldrPin = A0;        // Pin connected to the LDR
const int ledPins[5] = {2, 3, 4, 5, 6};  // Pins connected to the LEDs

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set LED pins as outputs
  }
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(ldrPin);  // Read the light intensity from LDR
  int brightness = map(sensorValue, 0, 1023, 0, 255);  // Map sensor value to LED brightness

  // Turn on LEDs based on the mapped brightness
  for (int i = 0; i < 5; i++) {
    if (brightness >= (i + 1) * 51) {
      digitalWrite(ledPins[i], HIGH);  // Turn LED on
    } else {
      digitalWrite(ledPins[i], LOW);   // Turn LED off
    }
  }

  // Print sensor value and brightness to serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Brightness: ");
  Serial.println(brightness);

  delay(500);  // Delay for stability and to reduce serial output
}
