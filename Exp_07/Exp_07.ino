/*
Experiment No. : 07
Statement : Blink an LED with two switches. One switch for increasing the blinking rate and other
for decreasing the blinking rate.
Date of Exp. : xx/xx/xxxx
Author : Tushar Rawte (A-06)
*/

const int ledPin = 2;  // Pin connected to the LED
const int increaseSwitchPin = 8;  // Pin connected to the increase switch
const int decreaseSwitchPin = 9;  // Pin connected to the decrease switch

int blinkDelay = 500;  // Initial blink delay in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  pinMode(increaseSwitchPin, INPUT_PULLUP);  // Set increase switch pin as input with pull-up resistor
  pinMode(decreaseSwitchPin, INPUT_PULLUP);  // Set decrease switch pin as input with pull-up resistor
}

void loop() {
  // Check if the increase switch is pressed
  if (digitalRead(increaseSwitchPin) == LOW) {
    increaseBlinkDelay();  // Increase the blink delay
  }
  
  // Check if the decrease switch is pressed
  if (digitalRead(decreaseSwitchPin) == LOW) {
    decreaseBlinkDelay();  // Decrease the blink delay
  }
  
  // Blink the LED with the current delay
  digitalWrite(ledPin, HIGH);  // Turn LED on
  delay(blinkDelay);  // Delay for blinkDelay milliseconds
  digitalWrite(ledPin, LOW);  // Turn LED off
  delay(blinkDelay);  // Delay for blinkDelay milliseconds
}

void increaseBlinkDelay() {
  // Increase the blink delay but ensure it does not exceed a maximum value
  if (blinkDelay < 2000) {
    blinkDelay += 100;  // Increase blink delay by 100 milliseconds
  }
}

void decreaseBlinkDelay() {
  // Decrease the blink delay but ensure it does not go below a minimum value
  if (blinkDelay > 100) {
    blinkDelay -= 100;  // Decrease blink delay by 100 milliseconds
  }
}
