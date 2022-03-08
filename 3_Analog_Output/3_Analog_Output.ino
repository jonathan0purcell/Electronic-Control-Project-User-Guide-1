/*
  Fade

  Fades in and out an LED using pulse width modulation (PWM)
  on the digital pin.

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/ebzfzvpYV8v 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// The minimum (OFF) and maximum (255) values of the PWM duty cycle
#define PWM_MIN 0
#define PWM_MAX 255

// Define the digital (PWM) pin number for the LED
#define LED_PIN 3

// The setup function runs once when you press reset or power the board
void setup() {
  // Set the pinMode of LED_PIN as OUTPUT (Reads in values)
  pinMode(LED_PIN, OUTPUT);
}

void fadeLED(const int START, const int STOP) {
  // Gradually increases or decreases the LED brightness
  // Based on the START and STOP values
  for (int pwm_val=START; pwm_val<=STOP; pwm_val++) {
    // Set the PWM duty cycle ("brightness") of the LED pin to pwm_val
    analogWrite(LED_PIN, pwm_val);
  }
}

// The loop function runs over and over again forever
void loop() {
  // Gradually increase the brightness of the LED
  fadeLED(PWM_MIN, PWM_MAX);

  // Gradually decrease the brightness of the LED
  fadeLED(PWM_MAX, PWM_MIN);

  // Wait 100ms before restarting the loop
  delay(100);
}
