#include <Arduino.h>
#line 1 "/Users/antonsoderberg/Documents/Arduino/hola_workshop_feb_2023/button/button.ino"
int buttonState = 0;
const int buttonPin = 2;

#line 4 "/Users/antonsoderberg/Documents/Arduino/hola_workshop_feb_2023/button/button.ino"
void setup();
#line 11 "/Users/antonsoderberg/Documents/Arduino/hola_workshop_feb_2023/button/button.ino"
void loop();
#line 4 "/Users/antonsoderberg/Documents/Arduino/hola_workshop_feb_2023/button/button.ino"
void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  // pinMode(buttonPin, INPUT); //Initialize pushbutton as an input
}

void loop()
{
  buttonState = digitalRead(buttonPin); // Read the state of the pushbutton value
  Serial.println(buttonState);
  // light up the LED if the button is pressed:
  if (buttonState == HIGH)
  {
    // turn LED on:
    digitalWrite(13, HIGH);
  }
  else
  {
    // turn LED off:
    digitalWrite(13, LOW);
  }
  delay(5);
}

