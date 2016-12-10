/*
  Blink & Print
  Turns on an LED on for a time, then off until the end of the cycle period.
  Uses the more useful millis() time function instead of the delay()
  David Smith
  This code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards, including Teensy 3. Pin 11 on Teensy 2.0
int led_pin = 13;

int t0 = 500;   // ON period (1/frequency)
int d1 = 160;   // ON duration

void setup() {
  // initialize the digital pin as an output.
  pinMode(led_pin, OUTPUT);
  while (!Serial && (millis() < 8000)) {  // continues if the monitor window is never opened
    ; // wait for serial port to connect. Needed for Leonardo & Teensyduino 3
  }
  Serial.println("Port connected.");
}


void loop() {
  if (millis() % t0 == 0) {
    digitalWrite(led_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.print(millis());
    Serial.print("\t ON");
    delay(1);   // wait until millis() will increment
  }
  if (millis() % t0 == d1) {
    digitalWrite(led_pin, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("  OFF");
    delay(1);
  }
}








