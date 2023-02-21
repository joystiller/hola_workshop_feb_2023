int photoPin = A2; // photoresistor is connected to analog pin 2

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int lightValue = analogRead(photoPin); // read the value from the photoresistor
  Serial.print("Light ");
  Serial.println(lightValue); // print the value to the serial monitor
  delay(10);                             // wait 10 milliseconds before the next loop for the analog-to-digital converter to settle
}
