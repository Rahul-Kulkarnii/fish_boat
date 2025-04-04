// Define pin connections
#define S1_PIN 6   
#define S2_PIN 5  
#define DIR_PIN 3   // Direction pin
#define STEP_PIN 4  // Pulse pin

int s1 =0;
int s2 =0;
int count = 0;
int range =0;

void setup() {
  Serial.begin(9600);
  pinMode(S1_PIN, INPUT);
  pinMode(S2_PIN, INPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);


}

int check_limits()
{

  count =0;
  while (s1 != 1 && s2 != 1)
  {
   // Rotate clockwise
  digitalWrite(DIR_PIN, LOW); // Set direction
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(500); // Adjust speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(500);
  s1 = digitalRead(S1_PIN);
  s2 = digitalRead(S2_PIN);
  }
  while (s1!=1)
  {
    // Rotate anti-clockwise
  digitalWrite(DIR_PIN, HIGH); // Set direction
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(500); // Adjust speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(500);
  s1 = digitalRead(S1_PIN);
  s2 = digitalRead(S2_PIN);
  count = count + 1;
  }
  return count;

}


void loop() {
  delay(5000);

  s1 = digitalRead(S1_PIN);
  s2 = digitalRead(S2_PIN);
  range = check_limits();
  for (int i = 0; i < range/2; i++) 
  {
   // Rotate clockwise
  digitalWrite(DIR_PIN, LOW); // Set direction
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(500); // Adjust speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(500);  
  }
  Serial.println(range);

  // Serial.print("S1 = ");
  // Serial.println(s1);
  // Serial.print("S2 = ");
  // Serial.println(s2);
  // delay(1000);

}