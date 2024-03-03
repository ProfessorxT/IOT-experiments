/*
Experiment No.	:	01
Statement		    :	Make running light pattern of 5 LEDs. It should run in both the directions continuously.
Date of Exp.	  :	xx/xx/xxxx
Author		      :	Tushar Rawte (A-06)
*/

const int led[5] = {2 , 3 , 4, 5, 6}; // Define the pins for LEDs using array

void setup() {
  for (int i = 0; i < 5; i++) { // Set all LED pins as outputs
    pinMode(led[i], OUTPUT);
  }
}

void loop() {

  for (int i = 0; i < 5; i++) { // Run the lights from left to right
    digitalWrite(led[i], HIGH); // Turn the led ON
    delay(150); // Delay for led
    digitalWrite(led[i], LOW); // Turn the led OFF
  }


  for (int i = 4; i >= 0; i--) { // Run the lights from right to left
    digitalWrite(led[i], HIGH); // Turn the led ON
    delay(150); // Delay for led
    digitalWrite(led[i], LOW);  // Turn the led OFF
  }
}

