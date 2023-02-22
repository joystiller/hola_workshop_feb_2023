// Thanks to Sound Simulator @ Youtube
//

char buffer[40]; // make an array for
int index = 0;   // for incoming serial data
int value = 0;   // for incoming serial data

// When using #define, the values are defined, and never replaces, unlike using "int ledPin = 6;", which is a variable that can be changed.
#define ledPin 6  // LED output
#define ledPin2 9 // Another LED output

void setup()
{
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop()
{
  index = 0;
  do
  {
    buffer[index] = Serial.read();   // Serial.read() reads the first byte in the serial buffer
    if (buffer[index] != -1)         // look if there is data. -1 means no data
      index = index + 1;             // if there is data (-1 is false), increment the index
  } while (buffer[index - 1] != 32); // 32 is the aschii kode for space. This is the condition that keeps the do loop going. It will keep going until it finds a space.

  value = atoi(buffer); // Finally found a space, the do-loop is broken. Now Convert string to integer

  if (value >= 0 && value <= 255)
  {                             // Check if the value is between 0 and 255
    analogWrite(ledPin, value); // Do something with the value, light up the LED?
    delay(5);
  }
  else if (value > 255 && value <= 511)
  {
    value = value - 256;
    analogWrite(ledPin2, value); // Do something, light up another LED?
    delay(5);
  }
}