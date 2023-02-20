# 1 "/Users/antonsoderberg/Documents/Arduino/hola_workshop_feb_2023/button/button.ino"
int buttonState = 0;
const int buttonPin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, 0x0);
  // pinMode(buttonPin, INPUT); //Initialize pushbutton as an input
}

void loop()
{
  buttonState = digitalRead(buttonPin); // Read the state of the pushbutton value
  Serial.println(buttonState);
  // light up the LED if the button is pressed:
  if (buttonState == 0x1)
  {
    // turn LED on:
    digitalWrite(13, 0x1);
  }
  else
  {
    // turn LED off:
    digitalWrite(13, 0x0);
  }
  delay(5);
}
