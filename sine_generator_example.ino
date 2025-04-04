// Define frequency (in Hz)
float frequency = 1;  // User can change this
float omega;            // Angular frequency: ω = 2πf

void setup() {
  Serial.begin(9600);   // Start serial communication
  omega = 2 * PI * frequency;
}

void loop() {
  unsigned long t = micros();               // Time in microseconds
  float timeInSeconds = t / 1e6;            // Convert to seconds
  int y = int(1000*sin(omega * timeInSeconds));     // sin(ωt)
  

  Serial.println(y);  // Send value to Serial Plotter
  delay(1);

}
