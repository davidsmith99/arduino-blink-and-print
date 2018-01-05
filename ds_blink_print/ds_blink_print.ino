/*
   Blink & Print
   Turns on an LED on for a time, then off until the end of the cycle period.
   Use of millis() time function instead of delay() so it does not block other operations
   Includes print messages to verify communication and times
   David Smith
   This code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards, including Teensy 3.
int PIN_LED = LED_BUILTIN;

unsigned int t_period = 1200;   // period [ms]
unsigned int t_on =      141;   // ON duration (must be < t_period)
const int TIMEOUT_MS = 5000;


void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  Serial.begin(57600);                    // rate ignored if using USB port comm
  while (!Serial && (millis() < TIMEOUT_MS)) {  // timeout lets program continue if the monitor window is never opened
    ; // wait for serial port to connect. Needed for Leonardo & Teensyduino 3
  }
  Serial.println("Serial port established for printing.");

  Serial.print("\n PERIOD: "); Serial.println(t_period);
}

void loop() {
  int t;
  static int t_prev = 0;
  static int t_count = t_period;

  t = millis();
  // test if it's the first time since millis() has incremented
  if (t > t_prev) {     // if so, then update outputs
    t_prev = t;
    if (t_count >= t_period) {
      t_count = 0;
      digitalWrite(PIN_LED, HIGH); // turn the LED on
      Serial.print("  ON: "); Serial.print(t_count);
    }
    else if (t_count == t_on) {
      digitalWrite(PIN_LED, LOW); // turn the LED off
      Serial.print("\t OFF: "); Serial.println(t_count); ;
    }
    t_count++;
  }
}

