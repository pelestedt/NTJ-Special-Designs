void writeConfiguration() {
  int wait = 1;
  int mem = 0;

//Delete up to and including firt $
byte fpos = Configstring.indexOf('$');
int msglength= Configstring.length();
Configstring=Configstring.substring(fpos+1, msglength);
  //Read SSID text up to first (,)
  //Write characters in to first 10 bytes (0-9)
  byte pos = Configstring.indexOf(',');
  String l_ssid = Configstring.substring(0, pos);
  l_ssid = l_ssid + ";";
  for (int a = 0; a < l_ssid.length()-1; a++) {
    EEPROM.write(mem, l_ssid[a]);
    mem = mem + 1;
  }
   //delete the stored value from the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());
 

  //Read loco name text up to next (,)
  //Write characters in to next 20 bytes (10-29)
  mem = 10;
  pos = Configstring.indexOf(',');
  String l_loconame = Configstring.substring(0, pos);
  l_ssid = l_loconame + ";";
  for (int a = 0; a < l_loconame.length(); a++) {
    EEPROM.write(mem, l_loconame[a]);
    mem = mem + 1;
  }
   //delete the stored value fro the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());


  //Read password text up to next (,)
  //Write characters in to next 20 bytes (30-49)

 mem = 30;
  pos = Configstring.indexOf(',');
  String l_password = Configstring.substring(0, pos);
  l_ssid = l_password + ";";
  for (int a = 0; a < l_password.length(); a++) {
    EEPROM.write(mem, l_password[a]);
    mem = mem + 1;
  }
  
  //delete the stored value froM the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());
 
 
  //Read server IP next 4 bytes separated by comma (50-53)
 for(mem=40;mem<44;mem++){
  pos = Configstring.indexOf(','); 
String l_IP = Configstring.substring(0, pos);
char carray[3];
   l_IP.toCharArray(carray, sizeof(l_IP));
 
byte   n = atoi(carray);
EEPROM.write(mem, n);
 Configstring = Configstring.substring(pos + 1, Configstring.length());
 }


  //Read server Net mask next 4 bytes separated by comma (54-57)
for(mem=44;mem<48;mem++){
   pos = Configstring.indexOf(','); 
String l_NM = Configstring.substring(0, pos);
char carray[3];
   l_NM.toCharArray(carray, sizeof(l_NM));
int   n = atoi(carray);
EEPROM.write(mem, n);
 Configstring = Configstring.substring(pos + 1, Configstring.length());
 }


  //read server port 2 byte (58-59)
mem=48;
pos = Configstring.indexOf(',');
String l_port = Configstring.substring(0, pos);
char carray[5];
   l_port.toCharArray(carray, sizeof(l_port));
int   n = atoi(carray);
EEPROM.write(mem, highByte(n));
mem=mem+1;
EEPROM.write(mem, lowByte(n));
//delete the stored value froM the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());
 

  //Read host name text up to next (,)
  //Write characters in to next 20 bytes (50-69)
 mem = 50;
  pos = Configstring.indexOf(',');
  String l_hostname = Configstring.substring(0, pos);
  l_ssid = l_hostname + ";";
  for (int a = 0; a < l_hostname.length(); a++) {
    EEPROM.write(mem, l_hostname[a]);
    mem = mem + 1;
  }
  //delete the stored value froM the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());
 

  //read PWM frequency 2 byte (80-81)
mem=70;
pos = Configstring.indexOf(',');
String l_pwm = Configstring.substring(0, pos);
//char carray[5];
   l_pwm.toCharArray(carray, sizeof(l_pwm));
   n = atoi(carray);
EEPROM.write(mem, highByte(n));
mem=mem+1;
EEPROM.write(mem, lowByte(n));
//delete the stored value froM the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());
 

//write  2 byte zero_speed

mem=72;
pos = Configstring.indexOf(',');
String l_zero = Configstring.substring(0, pos);
//char carray[5];
   l_zero.toCharArray(carray, sizeof(l_zero));
    n = atoi(carray);
EEPROM.write(mem, highByte(n));
mem=mem+1;
EEPROM.write(mem, lowByte(n));
//delete the stored value froM the beginning of the string
  Configstring = Configstring.substring(pos + 1, Configstring.length());
 

  //write  1 byte acceleration_time, mem
  //write  1 byte deceleration_time, mem
  //write  1 byte fullspeed
  //write  1 byte slowspeed, mem 
  //write  1 byte halfspeed, mem 
  //write  1 byte Shuntingspeed, mem 
  //write  1 byte startwhistle
  //write  1 byte approachwhistle
  //write  1 byte max_pulserate
  //write  1 byte min_pulserate
  //write  1 byte pulselength
  //write  1 byte smoketime 
  //write  1 byte creepspeed, mem 
  //write  1 byte mindwell
  //write  1 byte  maxdwell

for (mem=74; mem<89; mem++){
    pos = Configstring.indexOf(','); 
String l_param = Configstring.substring(0, pos);
char carray[3];
   l_param.toCharArray(carray, sizeof(l_param));
  byte   n = atoi(carray);
EEPROM.write(mem, n);
 Configstring = Configstring.substring(pos + 1, Configstring.length());
 }

  //write last  1 byte 
pos = Configstring.indexOf('$'); 
String l_maxdwell = Configstring.substring(0, pos);

   l_maxdwell.toCharArray(carray, sizeof(l_maxdwell));
   n = atoi(carray);
EEPROM.write(mem, n);

//write 123 in byte 500 to indicate that settings havebeen done
EEPROM.write(500, 123);


  EEPROM.commit();
  delay(500);
  sendConfiguration();
  delay(1000);
  ESP.restart();

  //

}//end
