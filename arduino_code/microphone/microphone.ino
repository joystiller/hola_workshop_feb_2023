int volume;

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  volume = analogRead(2);
  Serial.println(volume);
  delay(5);
}
