/*
  Blink & Print
  Turns on an LED on for a time, then off until the end of the cycle period.
  Illustrates use of millis() time function instead of the delay() so it does not block other operations
  Adds print msg as well to verify communication 
  David Smith
  This code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards, including Teensy 3. 
int led_pin = 13;

unsigned int t1 = 500;   // period (1/frequency)
unsigned int d1 = 160;   // ON duration

void setup() {
  // initialize the digital pin as an output.
  pinMode(led_pin, OUTPUT);
  while (!Serial && (millis() < 8000)) {  // timeout lets code continue if the monitor window is never opened
    ; // wait for serial port to connect. Needed for Leonardo & Teensyduino 3
  }
  Serial.println("Serial port active.");
}


void loop() {
  if (millis() % t1 == 0) {
    digitalWrite(led_pin, HIGH);   // turn the LED on
    Serial.print(millis());
    Serial.print("\t ON   ");
    delay(1);   // wait long enough for millis() to increment
  }
  if (millis() % t1 == d1) {
    digitalWrite(led_pin, LOW);    // turn the LED off
    Serial.print(millis());
    Serial.println("\tOFF");
    delay(1);
  }
}




