int knobValue = 0; 

void setup() {
  Serial.begin(9600);
  //Baud rate = speed at which the serial buffer is filled up.

}

void loop() {
  knobValue = analogRead(0); //Read sensor value sent to analog input 0
  Serial.println(knobValue); //Send to Pd
  delay(5);
}
