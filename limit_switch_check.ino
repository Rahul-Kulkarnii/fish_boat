// Define pin connections
#define S1_PIN 6   // Direction pin
#define S2_PIN 5  // Pulse pin


int s1 =0;
int s2 =0;

void setup() {
  Serial.begin(9600);
  pinMode(S1_PIN, INPUT);
  pinMode(S2_PIN, INPUT);

}

void loop() {

  s1 = digitalRead(S1_PIN);
  s2 = digitalRead(S2_PIN);
  Serial.print("S1 = ");
  Serial.println(s1);
  Serial.print("S2 = ");
  Serial.println(s2);
  delay(1000);

}