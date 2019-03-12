// Two-wire capacitance measurement. Working range: pF to 100s uF.
// CapValue(int IN_PIN, int OUT_PIN) function returns the value of a capacitor [in pF] that is directly connected to analog pins "IN_PIN" and "OUT_PIN".
// No circuit is needed. The precision/accuracy is acceptable considering the simplicity of the code and circuit.
// Developed based on a code published at [http://www.circuitbasics.com/how-to-make-an-arduino-capacitance-meter/]
// by Amir Farzad Forughi, UBC, March 2019.

//const int IN_PIN = A0;
//const int OUT_PIN = A2;
const float IN_STRAY_CAP_TO_GND = 24.48; // [pF] May need to be adjusted based on the chip (and even the pin)! (=24.48 for Uno, Leonardo, and their derivatives.)
const float IN_CAP_TO_GND  = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 34.8; // [kOhms] May need to be adjusted based on the chip (and even the pin)! (=34.8 for Uno, Leonardo, and their derivatives.)
const int MAX_ADC_VALUE = 1023;

float CapValue(int IN_PIN, int OUT_PIN) {
  pinMode(OUT_PIN, OUTPUT);
  pinMode(IN_PIN, OUTPUT);
  delay(100);

  pinMode(IN_PIN, INPUT);
  digitalWrite(OUT_PIN, HIGH);
  int val = analogRead(IN_PIN);
  digitalWrite(OUT_PIN, LOW);

  if (val < 1000)
  {
    pinMode(OUT_PIN, OUTPUT);
    pinMode(IN_PIN, OUTPUT);
    //delay(100);

    pinMode(IN_PIN, INPUT);
    digitalWrite(OUT_PIN, HIGH);
    int val = analogRead(IN_PIN);
    digitalWrite(OUT_PIN, LOW);

    if (val < 1000) {
      pinMode(IN_PIN, OUTPUT);
      float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);
      return capacitance; //pF
    }
  }

  else
  {
    pinMode(IN_PIN, OUTPUT);
    delay(1);
    pinMode(OUT_PIN, INPUT_PULLUP);
    unsigned long u1 = micros();
    unsigned long t;
    int digVal;

    do
    {
      digVal = digitalRead(OUT_PIN);
      unsigned long u2 = micros();
      t = u2 > u1 ? u2 - u1 : u1 - u2;
    }    while ((digVal < 1) && (t < 400000L));

    pinMode(OUT_PIN, INPUT);
    val = analogRead(OUT_PIN);
    digitalWrite(IN_PIN, HIGH);
    int dischargeTime = (int)(t / 1000L) * 5;
    delay(dischargeTime);
    pinMode(OUT_PIN, OUTPUT);
    digitalWrite(OUT_PIN, LOW);
    digitalWrite(IN_PIN, LOW);

    float capacitance = -(float)t / R_PULLUP / log(1.0 - (float)val / (float)MAX_ADC_VALUE);

    if (capacitance > 1000.0)
    {
      return (capacitance * 1000.0); //pF
    }

    else
    {
      return (capacitance * 1000.0); //pF
    }
  }
  while (micros() % 1000 != 0);
}


