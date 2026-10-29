volatile uint32_t count = 0; // Holds the count of button presses
const int ledPin = 3;        // LED connected to pin D3 via resistor

void incrementCount() {
  count++;
}

void setup() {
  Serial.begin(115200);
  
  // Configure button on pin 2 with internal pull-up
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), incrementCount, FALLING); 
  
  // Configure LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Toggle the LED state based on whether the press count is odd or even
  if (count % 2 == 1) {
    digitalWrite(ledPin, HIGH); // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED OFF
  }

  Serial.print("Interrupt count: ");
  noInterrupts();
  uint32_t currentCount = count;
  interrupts();
  
  Serial.println(currentCount);
  delay(100);
}