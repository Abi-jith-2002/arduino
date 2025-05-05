#define PIN_OUT A0  // Define the analog pin

// Variables to store the results
int sensorValue = 0;
int percentage = 0;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the defined pin
  sensorValue = analogRead(PIN_OUT);

  // Map the read value from the analog range (0-700) to a percentage (0-100)
  percentage = map(sensorValue, 0, 700, 0, 100);

  // Ensure the percentage is constrained within the range 0-100
  percentage = constrain(percentage, 0, 100);

  // Print the results to the serial monitor
  Serial.print("Read value: ");
  Serial.print(sensorValue);
  Serial.print(" | ");
  Serial.print(percentage);
  Serial.println("%");

  // Pause for 500 milliseconds before the next measurement
  delay(500);
}
