/*
Experiment No. : 10
Statement : Blink an LED in accordance with the brightness. Blinking frequency increases with
increase in brightness.
Date of Exp. : xx/xx/xxxx
Author : Tushar Rawte (A-06)
*/
const int ledPin = 2;      // Pin number for the LED
const int ldrPin = A0;  // Pin number for the ldr

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(ldrPin);
  
  // Map the light level to a blinking frequency
  int IntervalBlink = map(lightLevel, 0, 1023, 100, 2000);

  digitalWrite(ledPin, HIGH); // Turn on the LED
  delay(IntervalBlink);

  digitalWrite(ledPin, LOW);  // Turn off the LED
  delay(IntervalBlink);
  // Print the light level and blinking frequency to the serial monitor
  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print("\tBlinking Frequency: ");
  Serial.print(1000 / IntervalBlink); // Frequency in Hz
  Serial.println(" Hz");
  delay(100);
}
