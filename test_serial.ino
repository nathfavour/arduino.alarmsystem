void setup() {
  Serial.begin(9600);
  delay(100); // Small delay to allow serial to initialize
  Serial.println("Serial communication test");
}

void loop() {
  Serial.println("Hello, world!");
  delay(1000);
}
