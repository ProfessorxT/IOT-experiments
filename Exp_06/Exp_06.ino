/*
Experiment No. : 06
Statement : Design a 4-bit counter.
Date of Exp. : xx/xx/xxxx
Author : Tushar Rawte (A-06)
*/

// Define pins for LEDs and switch
const int led[4] = {2, 3, 4, 5}; // Array to store LED pin numbers
const int switchPin = 1; // Pin connected to the switch

int counter = 0; // Variable to store the counter value

void setup() {
  // Set LED pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
  }
  
  // Set switch pin as input with internal pull-up resistor
  pinMode(switchPin, INPUT_PULLUP);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  
  // Check if the switch is pressed
  if (digitalRead(switchPin) == LOW) {
    // Increment the counter
    counter++;
    
    // Reset the counter if it reaches 16
    if (counter == 16)
      counter = 0;
    
    // Display the binary representation of the counter on LEDs
    displayBinary();
    
    delay(500);
  }
}

// Function to display the binary representation of the counter on LEDs
void displayBinary() {
  for (int i = 0; i < 4; i++) {
    // Check each bit of the counter and set the corresponding LED
    if (bitRead(counter, i) == 1) {
      digitalWrite(led[i], HIGH); // Turn LED on
    } else {
      digitalWrite(led[i], LOW); // Turn LED off
    }
  }
}
