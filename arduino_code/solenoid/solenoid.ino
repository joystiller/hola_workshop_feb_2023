#define solenoidPin 9 // Output pin
#define buttonPin 3   // Input pin
int index = 0;
char buffer[40];
int value = 0;

void setup()
{
  pinMode(solenoidPin, OUTPUT); // Sets that pin as an output
  pinMode(buttonPin, INPUT);    // Sets that pin as an input
  Serial.begin(9600);
}

void loop()
{
  // Timer for solenoid
  /*
  digitalWrite(solenoidPin, HIGH); // Switch Solenoid ON
  delay(75);                       // Wait 1 Second
  digitalWrite(solenoidPin, LOW);  // Switch Solenoid OFF
  delay(1000);                     // Wait 1 Second
  */

  /*
   // Button for solenoid
    if (digitalRead(buttonPin) == HIGH) // If the button is pressed
   {
     digitalWrite(solenoidPin, HIGH); // Switch Solenoid ON
   }
   else
   {
     digitalWrite(solenoidPin, LOW); // Switch Solenoid OFF
   }
   */

  // Serial for solenoid. Don't forget to add the Serial.begin in setup.
  index = 0;
  do
  {
    buffer[index] = Serial.read();
    if (buffer[index] != -1)
      index = index + 1;
  } while (buffer[index - 1] != 32);

  value = atoi(buffer);
  if (value == 1)
  {
    digitalWrite(solenoidPin, HIGH); // Switch Solenoid ON
    Serial.println(value);
  }
  else
  {
    digitalWrite(solenoidPin, LOW); // Switch Solenoid OFF
    Serial.println(value);
  }
}