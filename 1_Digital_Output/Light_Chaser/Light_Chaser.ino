/*
  Light Chaser

  Creates a pattern between three LEDs where the light "bounces" from 
  one side to the other as seen below:

   ON     OFF    OFF
    _      _      _
  ( X )  (   )  (   )
   | \    | \    | \

   OFF    ON     OFF
    _      _      _
  (   )  ( X )  (   )
   | \    | \    | \

   OFF    OFF    ON
    _      _      _
  (   )  (   )  ( X )
   | \    | \    | \
   
   OFF    ON     OFF
    _      _      _
  (   )  ( X )  (   )
   | \    | \    | \

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/8FcHcW8JIDW 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// Define the pin number for the LEDs that we will be turning on and off
#define LED_PIN_A 2
#define LED_PIN_B 3
#define LED_PIN_C 4

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pins(Defined above) as an outputs.
  pinMode(LED_PIN_A, OUTPUT); 
  pinMode(LED_PIN_B, OUTPUT);
  pinMode(LED_PIN_C, OUTPUT);
}

// Function allows customizable patterns with the three LEDs - Also saves space in loop() function
void ledPattern(const int OUT_A, const int OUT_B, const int OUT_C) {
  // Turns on the three LEDs according to the arguments passed to the function
  digitalWrite(LED_PIN_A, OUT_A);
  digitalWrite(LED_PIN_B, OUT_B);
  digitalWrite(LED_PIN_C, OUT_C);
}

// The loop function runs over and over again forever
void loop() {
  ledPattern(HIGH, LOW, LOW);     // Turns on the first LED
  ledPattern(LOW, HIGH, LOW);     // Turns on the second LED
  ledPattern(LOW, LOW, HIGH);     // Turns on the third LED
  ledPattern(LOW, HIGH, LOW);     // Turns on the second LED (This acts as a "bounce" back)
  delay(100);
}
