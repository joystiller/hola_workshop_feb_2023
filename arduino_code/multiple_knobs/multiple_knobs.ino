int val[6]; //Array of six sensors in total

void setup() {
  Serial.begin(9600);
  //Baud rate = speed at which the serial buffer is filled up.

}

void loop() {
  //Read analog inputs one by one and send them to Pd
  for (int i = 0; i < 6; i++) {
    val[i] = analogRead(i);
    Serial.print(val[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(10);
}
