// Define pin connections
#define S1_PIN 6   
#define S2_PIN 5  
#define DIR_PIN 3   // Direction pin
#define STEP_PIN 4  // Pulse pin

int s1 =0;
int s2 =0;
int count = 0;
int range =0;
int current_state = 0;
int target_state = 0;
float frequency = 100;  // User can change this
float omega;            // Angular frequency: ω = 2πf
int speed =1000;



int check_limits()
{

  count =0;
  while (s1 != 1 && s2 != 1)
  {
   // Rotate clockwise
  digitalWrite(DIR_PIN, LOW); // Set direction
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(speed); // Adjust speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(speed);
  s1 = digitalRead(S1_PIN);
  s2 = digitalRead(S2_PIN);
  }
  while (s1!=1)
  {
    // Rotate anti-clockwise
  digitalWrite(DIR_PIN, HIGH); // Set direction
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(speed); // Adjust speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(speed);
  s1 = digitalRead(S1_PIN);
  s2 = digitalRead(S2_PIN);
  count = count + 1;
  }
  return count;

}

void calibrate_to_center(int range)
{
  for (int i = 0; i < range/2; i++) 
  {
   // Rotate clockwise
  digitalWrite(DIR_PIN, LOW); // Set direction
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(speed); // Adjust speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(speed);  
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(S1_PIN, INPUT);
  pinMode(S2_PIN, INPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  // range = check_limits();
  // calibrate_to_center(range);
  range = 686;
  range = range-30;
  Serial.println(range);
  omega = 2 * PI * frequency;

}



void loop() 
  {
  unsigned long t = micros();               // Time in microseconds
  float timeInSeconds = t / 1e6;            // Convert to seconds
  int y = int(1000*sin(omega * timeInSeconds));     // sin(ωt)
  target_state = map(y,-1000,1000, 0, range-30);
  Serial.print(target_state);
  while(target_state!=current_state)
  {
    if(target_state>current_state)
    {
      //move in clockwise direction by one step
      // digitalWrite(DIR_PIN, LOW); // Set direction
      // digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(speed); // Adjust speed
      // digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(speed);
      current_state = current_state +1;  
    }
    else
    {
       //move in anticlockwise direction by one step
      // digitalWrite(DIR_PIN, HIGH); // Set direction
      // digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(speed); // Adjust speed
      // digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(speed);  
      current_state = current_state-1;  
    }
    // Serial.print(" Current_state =  ");
    Serial.println(current_state);
  }
  }



