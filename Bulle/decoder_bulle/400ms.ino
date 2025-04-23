void every400ms()
{
  // code to be repeated every 400ms
  //check and set travel direction if current_PWM==0
  if (current_PWM == 0) {
    if (1 == set_direction)digitalWrite(DIR, LOW); //Drop direction relay
    if (0 == set_direction)digitalWrite(DIR, HIGH); //Pull direction relay
  }

  //Function key 0, Otput 1, Light on/off
  if (FunctionKey[0] == 1) { digitalWrite(OUT1, HIGH);  }
  if (FunctionKey[0] == 0) { digitalWrite(OUT1, LOW);  }

  //Function key 1, Otput 2, Spare
  if (FunctionKey[1] == 1){digitalWrite(OUT2, HIGH);}
  if (FunctionKey[1] == 0){digitalWrite(OUT2, LOW); }

  //Function key 2, Otput 3, Spare
  if (FunctionKey[2] == 1){digitalWrite(OUT3, HIGH);}
  if (FunctionKey[2] == 0){digitalWrite(OUT3, LOW); }

  //Function key 3, Otput 4, Whistle
  if (FunctionKey[3] == 1){digitalWrite(OUT4, HIGH);}
  if (FunctionKey[3] == 0 && NEXTTIMER == false){digitalWrite(OUT4, LOW);  } //Function key 4, Whistle

  //Function key 4 and Out 5 reserved for sound
  if (FunctionKey[4] == 1) {
    sound = true;
  }
  if (FunctionKey[4] == 0) {
    sound = false;
  }

  //Out 6 reserved for smoke
  if (FunctionKey[5] == 1)smoke = true;
  if (FunctionKey[5] == 0)smoke = false;

  //Function key 7 reserved for double short whistle

  //Function key 8 reserved for Emergency stop

  //Function key 9 reserved for next station
  if (FunctionKey[9] == 1) {
    NEXTSTATION = true;  //Function key 9
    NSphase = 1;
    FunctionKey[9] = 0;
  }

  //Function key 10 reserved for shunting
  if (FunctionKey[10] == 1) {
    shunting = true;
  }
  if (FunctionKey[10] == 0) {
    shunting = false;
  }


  //Function key 11 reserved for next station with remote activation via digital input
  if (FunctionKey[11] == 1) {
    NEXTSTATIONREMOTE = true;
  }
  if (FunctionKey[11] == 0 ) {
    FunctionKey[11] = false;  //Function key 11
    NEXTSTATIONREMOTE = false;
  }

  //Function key 12 pendelum traffic
  if (FunctionKey[12] == 1) {
    PENDULUM = true;
  }
  if (FunctionKey[12] == 0 ) {
    FunctionKey[12] = false;
    PENDULUM = false;
  }
  
}
