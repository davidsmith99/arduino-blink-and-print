/*
  Blink & Print
  Turns on an LED on for a time, then off until the end of the cycle period.
  Use of millis() time function instead of delay() so it does not block other operations
  Includes print messages to verify communication and times
  David Smith
  This code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards, including Teensy 3.
int PIN_LED = 13;

unsigned int t1 = 900;   // period (ON+OFF duration) (1/frequency)
unsigned int d1 = 121;   // ON duration

void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  Serial.begin(57600);                    // supplied baud rate doesn't matter for Teensy 3 in Arduino monitor
  while (!Serial && (millis() < 5000)) {  // timeout lets program continue if the monitor window is never opened
    ; // wait for serial port to connect. Needed for Leonardo & Teensyduino 3
  }
  Serial.println("Serial port established for printing.");
}

void loop() {
 int t = millis();
  if (t % t1 == 0) {                           // modulo divide sets interval
    digitalWrite(PIN_LED, HIGH);               // turn the LED on
    Serial.print(t); Serial.print("\t ON   ");
  }
  if (t % t1 == d1) {
    digitalWrite(PIN_LED, LOW);                // turn the LED off
    Serial.print(t); Serial.println("\t OFF");
  }
  delay(1);  // wait long enough for millis() to increment; otherwise multiple matches cause repeated output
}




