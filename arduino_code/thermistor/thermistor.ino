// Since the thermistor is a variable resistor, we’ll need to measure the resistance before we can calculate the temperature. However, the Arduino can’t measure resistance directly, it can only measure voltage.

// The Arduino will measure the voltage at a point between the thermistor and a known resistor. This is known as a voltage divider. The voltage at the point between the two resistors is proportional to the resistance of the thermistor.

// Input to Arduino measures voltage, and then multiplies divides to 1023 values.

//
#include <math.h>

float R1 = 100000;                                             // known resistor
float reading, logR2, R2, T;                                   // variables for calculations
float c1 = 3.354016e-03, c2 = 2.909670e-04, c3 = 1.632136e-06; // thermistor coefficients

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  reading = analogRead(0);
  // convert reading to celcius
  R2 = R1 * (1023 / reading - 1);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Serial.println(T);

  delay(1000);
}
