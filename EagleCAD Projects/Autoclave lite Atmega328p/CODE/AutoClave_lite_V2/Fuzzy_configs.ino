void fuzzy_mf_init() {
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

void fuzzy_loop_heater() {

  //temp read + offset here if prog runing
  temp_read = thermocouple.readCelsius();

  if (temp_read <= temp_desired) {
    // Getting a error value
    temp_error = temp_desired - temp_read + temp_offset;
    // Set the random value as an input
    fuzzy->setInput(1, temp_error);
    // Running the Fuzzification
    fuzzy->fuzzify();
    // Running the Defuzzification
    fuzzy_def_output = fuzzy->defuzzify(1);
    angle_fired = (byte)fuzzy_def_output;
    heater_on_flag=true;
  }
  else
  {
    heater_on_flag=false;
  }
}

void zero_cross_isr() {
  if (heater_on_flag) {
    angle_counter = 0;
    angle_counter++;
    if (angle_counter >= 10) angle_counter = 0;
    if (angle_counter >= angle_fired) digitalWrite(heater_triac, LOW);
    else digitalWrite(heater_triac, HIGH);
  }
  else
    digitalWrite(heater_triac, LOW);
}
