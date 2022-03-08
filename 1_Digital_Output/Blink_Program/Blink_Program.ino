/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly, as seen below.

    _
  ( X )  ON
   | \
    _
  (   )  OFF
   | \

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/fPWMrij7a2X 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// Define the pin number for the LED that we will be turning on and off
#define LED_PIN 2

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin LED_PIN (Defined above) as an output.
  pinMode(LED_PIN, OUTPUT); 
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);   // Turn the LED on (HIGH is the voltage level)
  delay(1000);                   // Wait for a second
  digitalWrite(LED_PIN, LOW);    // Turn the LED off by making the voltage LOW
  delay(1000);                   // Wait for a second
}
