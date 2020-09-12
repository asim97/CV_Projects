#include <Fuzzy.h>

// Instantiating a Fuzzy object
Fuzzy *fuzzy = new Fuzzy();

String inString = "";    // string to hold input

void setup()
{
  // Set the Serial output
  Serial.begin(9600);
  // Instantiating a FuzzyInput object
  FuzzyInput *fuzzy_error = new FuzzyInput(1);
  // Instantiating a FuzzySet object
  FuzzySet *NEG = new FuzzySet(-50, -50, -30, -15);
  // Including the FuzzySet into FuzzyInput
  fuzzy_error->addFuzzySet(NEG);
  // Instantiating a FuzzySet object
  FuzzySet *SNEG = new FuzzySet(-30, -15, -15, 0 );
  // Including the FuzzySet into FuzzyInput
  fuzzy_error->addFuzzySet(SNEG);
  // Instantiating a FuzzySet object
  FuzzySet *ZERO = new FuzzySet(-15, 0, 0, 15);
  // Including the FuzzySet into FuzzyInput
  fuzzy_error->addFuzzySet(ZERO);
  // Instantiating a FuzzySet object
  FuzzySet *SPOZ = new FuzzySet(0, 15, 15, 30);
  // Including the FuzzySet into FuzzyInput
  fuzzy_error->addFuzzySet(SPOZ);
  // Instantiating a FuzzySet object
  FuzzySet *POZ = new FuzzySet(15, 30, 50, 50);
  // Including the FuzzySet into FuzzyInput
  fuzzy_error->addFuzzySet(POZ);
  // Including the FuzzyInput into Fuzzy
  fuzzy->addFuzzyInput(fuzzy_error);

  // Instantiating a FuzzyOutput objects
  FuzzyOutput *fuzzy_phase_output = new FuzzyOutput(1);
  // Instantiating a FuzzySet object
  FuzzySet *Z = new FuzzySet(0, 0, 0, 50);
  // Including the FuzzySet into FuzzyOutput
  fuzzy_phase_output->addFuzzySet(Z);
  // Instantiating a FuzzySet object
  FuzzySet *L = new FuzzySet(0, 50, 50, 90);
  // Including the FuzzySet into FuzzyOutput
  fuzzy_phase_output->addFuzzySet(L);
  // Instantiating a FuzzySet object
  FuzzySet *M = new FuzzySet(50, 90, 90, 130);
  // Including the FuzzySet into FuzzyOutput
  fuzzy_phase_output->addFuzzySet(M);
  // Instantiating a FuzzySet object
  FuzzySet *H = new FuzzySet(90, 130, 130, 170);
  // Including the FuzzySet into FuzzyOutput
  fuzzy_phase_output->addFuzzySet(H);
  // Instantiating a FuzzySet object
  FuzzySet *VH = new FuzzySet(130, 170, 170, 170);
  // Including the FuzzySet into FuzzyOutput
  fuzzy_phase_output->addFuzzySet(VH);
  // Including the FuzzyOutput into Fuzzy
  fuzzy->addFuzzyOutput(fuzzy_phase_output);

  // Building FuzzyRule "IF Error = NEG THEN Angle = VH"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *if_error_NEG = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  if_error_NEG->joinSingle(NEG);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *then_angle_VH = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  then_angle_VH->addOutput(VH);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule01 = new FuzzyRule(1, if_error_NEG, then_angle_VH);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule01);

  // Building FuzzyRule "IF Error = SNEG THEN Angle = H"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *if_error_SNEG = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  if_error_SNEG->joinSingle(SNEG);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *then_angle_H = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  then_angle_H->addOutput(H);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule02 = new FuzzyRule(2, if_error_SNEG, then_angle_H);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule02);

  // Building FuzzyRule "IF Error = ZERO THEN Angle = M"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *if_error_ZERO = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  if_error_ZERO->joinSingle(ZERO);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *then_angle_M = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  then_angle_M->addOutput(M);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule03 = new FuzzyRule(3, if_error_ZERO, then_angle_M);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule03);

  // Building FuzzyRule "IF Error = SPOZ THEN Angle = L"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *if_error_SPOZ = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  if_error_SPOZ->joinSingle(SPOZ);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *then_angle_L = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  then_angle_L->addOutput(L);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule04 = new FuzzyRule(4, if_error_SPOZ, then_angle_L);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule04);

  // Building FuzzyRule "IF Error = POZ THEN Angle = Z"
  // Instantiating a FuzzyRuleAntecedent objects
  FuzzyRuleAntecedent *if_error_POZ = new FuzzyRuleAntecedent();
  // Creating a FuzzyRuleAntecedent with just a single FuzzySet
  if_error_POZ->joinSingle(POZ);
  // Instantiating a FuzzyRuleConsequent objects
  FuzzyRuleConsequent *then_angle_Z = new FuzzyRuleConsequent();
  // Including a FuzzySet to this FuzzyRuleConsequent
  then_angle_Z->addOutput(Z);
  // Instantiating a FuzzyRule objects
  FuzzyRule *fuzzyRule05 = new FuzzyRule(5, if_error_POZ, then_angle_Z);
  // Including the FuzzyRule into Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule05);
}

void loop()
{
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      // Printing something
      Serial.println("\n\n\nEntrance: ");
      Serial.print("\t\t\tError: ");
      Serial.println(inString.toInt());
      // Set the random value as an input
      fuzzy->setInput(1, inString.toInt());
      // Running the Fuzzification
      fuzzy->fuzzify();
      // Running the Defuzzification
      // Running the Defuzzification
      float fuzzy_def_output = fuzzy->defuzzify(1);
      float traic_siganl;
      traic_siganl = mapf(fuzzy_def_output, 0, 170, 0.0, 1.0);
      // Printing something
      Serial.println("Result: ");
      Serial.println(fuzzy_def_output);
      Serial.print("\t\t\tAngle: ");
      Serial.println(1 - traic_siganl);

      // clear the string for new input:
      inString = "";
    }
  }
}


double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
  return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

