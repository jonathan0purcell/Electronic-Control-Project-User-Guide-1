/*
  Blink and Pushbutton (No delay)

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function, depending on the pushbutton state.

  Due to the nature of the Arduino, it is not able to run code (e.g. 
  fade, blink an LED) while the delay function is used. Hence, to 
  solve this issue, another way to "delay" the program is used.

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/7IyNhV3EAhh 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// Define the pin number for the LED that we will be turning on and off
#define LED_PIN 2

// Define the pin number for the pushbutton
#define PB_PIN 3

int ledState = LOW;               // Variable used to set the LED state
unsigned long previousMillis = 0; // Used to store the last time LED was updated
const long interval = 1000;        // Interval at which to blink the LED

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT); 

  // Initialize the digital pushbutton pin as an input.
  pinMode(PB_PIN, INPUT); 
}

void blinkLED(){
  // Check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(LED_PIN, ledState);
  }
}

// The loop function runs over and over again forever
void loop() {
  if (digitalRead(PB_PIN)) { blinkLED(); }
}
