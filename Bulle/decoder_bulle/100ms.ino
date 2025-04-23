void every100ms()
{
  // code to be repeated every 100ms

  //Activate short double whistle
  if (FunctionKey[7] == true && NWphase == 0) {
    digitalWrite(OUT4, HIGH);
    nextwhistle = millis() + 500;
    NWphase = 1;
    NEXTTIMER = true;
  }
  if (NWphase == 1 && millis() > nextwhistle) {
    digitalWrite(OUT4, LOW);
    nextwhistle = millis() + 500;
    NWphase = 2;
  }
  if (NWphase == 2 && millis() > nextwhistle) {
    digitalWrite(OUT4, HIGH);
    nextwhistle = millis() + 500;
    NWphase = 3;
  }
  if (NWphase == 3 && millis() > nextwhistle) {
    digitalWrite(OUT4, LOW);
    NWphase = 0;
    NEXTTIMER = false;
    FunctionKey[7] = false;
  }

  //set emergency stop on and don not turn it off unless speed is set to 0
  if (FunctionKey[8] == true) {
    //sound the whistle twice at emergency stop
    if (set_speed > 0) {
      FunctionKey[7] = true;
    }
    EMS = true;
    EMS_stopped = true;
    NEXTSTATION = false;
    NEXTSTATIONREMOTE = false;
    PENDULUM = false;
    Pphase = 0;
    NSphase = 0;
    NSRphase = 0;
    set_speed = 0;
    //intln("Emergency stop sets speed to zero");
  }

  if (FunctionKey[8] == false && set_speed == 0 && EMS_stopped == true && throttle_speed == 0) {
    EMS = false;
    desired_speed = 0;
    EMS_stopped = false;
  }
  //Handle puff pulse generation
  //check if puff is defined
  if (sound == true ) {
    if (max_pulserate > 0 && min_pulserate > 0) {
      // check that we are actually moving and set output voltage on OUT5
      if (desired_speed > 0 ) {
        analogWrite(OUT5, read_speed);
        if (desired_speed > 0 && read_speed < 55)analogWrite(OUT5, 50);
      }
      if (desired_speed == 0 && 0 == read_speed) {
        analogWrite(OUT5, 50);
        int slump = random(1, 175);
        if (10==slump){analogWrite(OUT5, 70); delay(400); analogWrite(OUT5,0);delay(200);}
      }
    }
  }
  else
  { analogWrite(OUT5, 0);
  }//end of puff pulse handling
}
