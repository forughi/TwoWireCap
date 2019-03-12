/*
  Two-wire capacitance measurement. Working range: pF to 100s uF.

  CapValue(int IN_PIN, int OUT_PIN) function returns the value of a capacitor [in pF] that is directly connected to analog pins "IN_PIN" and "OUT_PIN".
  Also prints the results to the Serial Monitor.

  The circuit:
  - No circuit is needed.
  - Please connect the capacitor directly to the analog pins.

  Developed based on a code published at [http://www.circuitbasics.com/how-to-make-an-arduino-capacitance-meter/]
  by Amir Farzad Forughi, UBC, March 2019.

  This example code is in the public domain.

*/

#include <TwoWireCap.h>

const int APIN1 = A0;  //First  Analog pin 
const int APIN2 = A2;  //Second Analog pin

void setup()
{
  Serial.begin(9600); //Initialize serial communications at 9600 bps.
}

void loop()
{
  float result = CapValue(APIN1, APIN2);
  Serial.println(result);
}
