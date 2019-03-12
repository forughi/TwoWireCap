# TwoWireCap
Two-wire capacitance measurement for Arduino. Working range: pF to 100s uF.

CapValue(int IN_PIN, int OUT_PIN) function returns the value of a capacitor [in pF] that is directly connected to analog pins "IN_PIN" and "OUT_PIN".

No circuit is needed. The precision/accuracy is acceptable considering the simplicity of the code and circuit.

Developed based on a code published at [http://www.circuitbasics.com/how-to-make-an-arduino-capacitance-meter/]

(A. F. Forughi, UBC, March 2019.)

# Installation
Download from https://github.com/forughi/TwoWireCap/archive/master.zip.

Extract it to the libraries folder inside your Sketchbook. Default is [user]\Arduino\libraries.
