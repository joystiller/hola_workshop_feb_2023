#include <CapacitiveSensor.h>

// if serial monitor moves really slowly, it's probably due to a faulty cable or broken connection somewhere.

/*
CapacitiveSensor cs0 = CapacitiveSensor(2, 3);
CapacitiveSensor cs1 = CapacitiveSensor(4, 5);
CapacitiveSensor cs2 = CapacitiveSensor(6, 7);

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  long measurement = cs0.capacitiveSensor(30);
  long measurement2 = cs1.capacitiveSensor(30);
  long measurement3 = cs2.capacitiveSensor(30);
  Serial.println(measurement);
  Serial.println(measurement2);
  Serial.print´ln(measurement3);
  delay(10);
}
*/

// Undersök sen hur man ska loopa igenom alla sensorer. Det går ju inte om man inte först skapar en array med alla sensorer. Fråga chatGPT om en lösning.

// Multiple sensors
CapacitiveSensor cs[3] = {
    CapacitiveSensor(2, 3),
    CapacitiveSensor(4, 5),
    CapacitiveSensor(6, 7)};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Read digital inputs one by one and send them to Pd
  for (int i = 0; i < 3; i++)
  {
    long val = cs[i].capacitiveSensor(30);
    Serial.print(val);
    Serial.print(" ");
  }
  Serial.println();
  delay(10);
}
