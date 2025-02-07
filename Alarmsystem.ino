// Define pin constants
const int BUZZER_PIN = 8;
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

// Define constants for calculations
const float SOUND_SPEED = 0.034; // Speed of sound in cm/us
const float CM_TO_INCH = 0.393701; // Conversion factor from cm to inch

// Define alarm threshold
const int THRESHOLD_DISTANCE_CM = 50; // Distance threshold in cm

// Variables for timing and distance
unsigned long lastTriggerTime = 0;
float distanceCm = 0.0;

void setup() {
  // Set pin modes
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize trigger pin state
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor every 50ms
  if (millis() - lastTriggerTime >= 50) {
    triggerSensor();
    lastTriggerTime = millis();
  }

  // Check distance and activate alarm
  if (distanceCm <= THRESHOLD_DISTANCE_CM) {
    activateAlarm();
  } else {
    deactivateAlarm();
  }

  // Add a status message to indicate the sensor is working
  Serial.println("Sensor active and reading values.");
}

void triggerSensor() {
  // Generate a short ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the echo pulse
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);

  // Check for invalid duration (potential wiring or sensor issue)
  if (duration == 0) {
    Serial.println("Error: No echo pulse received. Check wiring and sensor.");
    distanceCm = 0; // Set distance to 0 to avoid false alarms
    return; // Exit the function
  }

  // Calculate the distance in centimeters
  distanceCm = (duration * SOUND_SPEED) / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm | ");
  Serial.print(distanceCm * CM_TO_INCH);
  Serial.println(" in");
}

void activateAlarm() {
  // Activate the buzzer
  tone(BUZZER_PIN, 500); // Play a tone at 500 Hz
}

void deactivateAlarm() {
  // Deactivate the buzzer
  noTone(BUZZER_PIN);
}