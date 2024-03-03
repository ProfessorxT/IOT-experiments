/*
Experiment No. : 9
Statement : Lit an LED with brightness equal to 0%, 25%, 50%, 75%, 100% via serial monitor
window.
Date of Exp. : xx/xx/xxxx
Author : Tushar Rawte (A-06)
*/

const int ledPin = 2;   // Pin connected to the LED
int brightness = 0;     // Variable to store the brightness level

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {  
    char command = Serial.read();  // Read the command from serial
    
    // Process the command and set the brightness level accordingly
    switch (command) {
      case '0':
        brightness = 0;
        break;
      case '1':
        brightness = 64;  // 25% brightness (approximately 64/255)
        break;
      case '2':
        brightness = 128; // 50% brightness (approximately 128/255)
        break;
      case '3':
        brightness = 192; // 75% brightness (approximately 192/255)
        break;
      case '4':
        brightness = 255; // 100% brightness
        break;
    }
    
    analogWrite(ledPin, brightness); // Set the LED brightness
  }
}
