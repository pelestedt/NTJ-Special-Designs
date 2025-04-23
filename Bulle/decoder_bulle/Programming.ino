void Programming() {

  //check if clientdata starts with "Getconfig"
  if (Data.startsWith("Getconfig")) {
    sendConfiguration();
    client.println(Configuration);
    client.flush();
    Data = "";
  }
  //check if clientdata starts with "Writeconfig"
  if (Data.startsWith("Writeconfig")) {
    Configstring = Data;
    writeConfiguration();
    Data = "";
  }
  //check if clientdata starts with "Calibrate"
  if (Data.startsWith("Calibrate")) {
    //Slowly increase PWM until motor turns
    int p = 255;
    for (int i = 0; i < 255; i++) {
      analogWrite(PWM, p);
      delay(400);
      analogWrite(PWM, 0);
      //wait for the analogue input to stabalize
      delay(2);
      //read the value 4 times and make an average
      read_speed = analogRead(A0);
      read_speed = read_speed + analogRead(A0);
      read_speed = read_speed / 2;
      analogWrite(PWM, p);
      p = p - 1;
      if (read_speed < 1) {
        analogWrite(PWM, 0);
        //When motor stops to turn, store the value in the zero_speed variable
        //write  2 byte zero_speed
        EEPROM.write(72, highByte(p));
        EEPROM.write(73, lowByte(p));
        EEPROM.commit();
        delay(1000);
        ESP.restart();
      }
    }
  }

  //check if clientdata starts with "PWM"
  if (Data.startsWith("PWM")) {
    //Slowly increase PWM freq to find optimum response
    int maxa = 0;
    int optfrq = 0;
    int testfart = 4 * zero_speed;
    analogWrite(PWM, 500);
    delay(500);
    analogWrite(PWM, testfart);
    for (int i = 0; i < 1501; i++) {
      analogWrite(PWM, testfart);
      analogWriteFreq(100 + (10 * i));
      delay(250);
      analogWrite(PWM, 0);
      //wait for the analogue input to stabalize
      delay(2);
      //read the value 2 times and make an average
      read_speed = analogRead(A0);
      read_speed = read_speed + analogRead(A0);
      read_speed = read_speed / 2;
      analogWrite(PWM, testfart);
      //int(100 + (10 * i));
      //intln(" / ");
      //intln(read_speed);
      if (read_speed > maxa) {
        maxa = read_speed;
        optfrq = 100 + (10 * i);
      }
      if (read_speed == 0) break;
    }
    analogWrite(PWM, 0);
    //When motor stops to turn, store the value in the zero_speed variable
    //write  2 byte zero_speed
    EEPROM.write(70, highByte(optfrq));
    EEPROM.write(71, lowByte(optfrq));
    EEPROM.commit();
    delay(1000);
    ESP.restart();
  }
}
