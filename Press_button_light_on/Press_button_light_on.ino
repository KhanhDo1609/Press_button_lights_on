const byte BUTTON_PIN = 2;
const byte LED_PIN = 12;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(30);  // Debounce the button

    if (digitalRead(BUTTON_PIN) == LOW) {
      digitalWrite(LED_PIN, HIGH);
      delay(2000);  // LED on for 2 seconds
      digitalWrite(LED_PIN, LOW);

      // Wait for release so holding it doesn't repeat
      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }
      delay(30);
    }
  }
}