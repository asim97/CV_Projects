/*
  Arduino Code to Send the 2 values of CH1 and CH2
  using Serial to LabView VISA For analysing and
  Show the final Data.

  Coded in 14/4/2018 by Mohamed Asim Abdullah
*/

const byte CH1 = A1;       // Analog Input pin For CH1
const byte CH2 = A2;       // Analog Input pin For CH1

void setup() {
  Serial.begin(115200);   // Start Serial communication with speed of 115200 bps
  while (!Serial);        // Wait for Serial communication (authentication)
}

void loop() {
  // Print the data in format of (ch1,ch2) ,So LabView can identfiy both them
  Serial.print("(");
  Serial.print(analogRead(CH1));
  Serial.print(",");
  Serial.print(analogRead(CH2));
  Serial.print(")");
  Serial.print('\n');
  delay(10);
}
