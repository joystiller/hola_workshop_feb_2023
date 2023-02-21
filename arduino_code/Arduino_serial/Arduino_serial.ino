int inByte = 0;  // for incoming serial data
char buffer[40]; // for incoming serial data
int index = 0;   // for incoming serial data
int value = 0;   // for incoming serial data
#define ledPin 6 // LED output

void setup()
{
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop()
{
  index = 0;
  do
  {
    buffer[index] = Serial.read();
    if (buffer[index] != -1)
      index = index + 1;
  } while (buffer[index - 1] != 32);
  value = atoi(buffer); // Data sent FROM pure data.
  analogWrite(ledPin, value);
  // Serial.println(readSensor());
  delay(5);
}

//  This function returns the analog data to calling function
int readSensor()
{
  int outputValue = map(value, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data
  analogWrite(ledPin, outputValue);              // generate PWM signal
  return outputValue;                            // Return analog rain value
}