void Getsettings(){
//intln("");
//intln("Skriver ut EEprominst");
//SSID 10 bytes 0-9
   ssid="";
   for (int mem=0; mem<10; mem++){ ssid += char(EEPROM.read(mem));}
   ssid.trim();
//int("ssid "); //intln(ssid);

//Loconame 20 bytes 10-29
loco_name="";
for (int mem=10; mem<30; mem++){ loco_name += char(EEPROM.read(mem));}
//int("loco_name "); //intln(loco_name);
myID=loco_name.toInt();

//Password 10 bytes 30-39
password="";
for (int mem=30; mem<40; mem++){ password += char(EEPROM.read(mem));}
password.trim();
//int("password "); //intln(password);

//PWM frequency 2 bytes 70-71
pwmfrq=(256*EEPROM.read(70))+EEPROM.read(71);
//int("pwmfrq "); //intln(pwmfrq);

//Zero_speed 2 bytes
zero_speed=(256*EEPROM.read(72))+EEPROM.read(73);
//int("zero_speed "); //intln(zero_speed);

 //write  1 byte acceleration_time, 
acceleration_time=EEPROM.read(74);
//int("acceleration_time "); //intln(acceleration_time);

//write  1 byte deceleration_time,
deceleration_time=EEPROM.read(75);
//int("deceleration_time "); //intln(deceleration_time); 

//write  1 byte fullspeed
fullspeed=EEPROM.read(76);
//int("fullspeed "); //intln(fullspeed);
  
  //write  1 byte slowspeed
slowspeed=EEPROM.read(77);
//int("slowspeed "); //intln(slowspeed);
 
  //write  1 byte halfspeed
halfspeed=EEPROM.read(78);
//int("halfspeed "); //intln(halfspeed);

  //write  1 byte Shuntingspeed
Shuntingspeed=EEPROM.read(79);
//int("Shuntingspeed "); //intln(Shuntingspeed);
  
  //write  1 byte startwhistle
startwhistle=EEPROM.read(80);
//int("startwhistle "); //intln(startwhistle);

  
  //write  1 byte approachwhistle
approachwhistle=EEPROM.read(81);
//int("approachwhistle "); //intln(approachwhistle);
  
  //write  1 byte max_pulserate
max_pulserate =EEPROM.read(82);
//int("max_pulserate "); //intln(max_pulserate);
  
  //write  1 byte min_pulserate
min_pulserate=EEPROM.read(83);
//int("min_pulserate "); //intln(min_pulserate);
  
  //write  1 byte pulselength
pulselength=EEPROM.read(84);
//int("pulselength "); //intln(pulselength);
  
 //Smoketime
smoke_timer =EEPROM.read(85);
//int("smoke_timer "); //intln(smoke_timer);
 
//creepspeed
creepspeed=EEPROM.read(86);
//int("creepspeed "); //intln(creepspeed);

//mindwell
mindwell=EEPROM.read(87);
//int("mindwell "); //intln(mindwell);

//maxdwell 
maxdwell=EEPROM.read(88);
//int("maxdwell "); //intln(maxdwell);

}// Slut Getsettings
