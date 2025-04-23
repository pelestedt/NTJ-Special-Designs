void sendConfiguration() {
  int mem = 0;
  //  byte Hbyte = 0;
//  byte Lbyte = 0;
//  byte configdata[200];
  //String Configuration;
  //Add SSID
  Configuration = "";
  for (mem=0; mem<10; mem++){ Configuration += char(EEPROM.read(mem));}
  Configuration += ",";

//Add locomotive name
  for (mem=10; mem<30; mem++){ Configuration += char(EEPROM.read(mem));}
  Configuration += ",";

//Add password
    for (mem=30; mem<40; mem++){ Configuration += char(EEPROM.read(mem));}
  Configuration += ",";

//Add IP address
    for (mem=40; mem<44; mem++){ Configuration += EEPROM.read(mem);Configuration += ",";}
  
  
//Add netmask
for (mem=44; mem<48; mem++){ Configuration += EEPROM.read(mem);Configuration += ",";}
  

//Add server port
mem=48;
int port=(256*EEPROM.read(mem))+EEPROM.read(mem+1);
Configuration += port;
Configuration += ",";

//Add Host name
mem=50;
for (mem=50; mem<70; mem++){ Configuration += char(EEPROM.read(mem));}
  Configuration += ",";

//Add PWM frequency
mem=70;
int pwm=(256*EEPROM.read(mem))+EEPROM.read(mem+1);
Configuration += pwm;
Configuration += ",";
mem=mem+2;

//Add start offset dutycycle
int sd=(256*EEPROM.read(mem))+EEPROM.read(mem+1);
Configuration += sd;
Configuration += ",";
mem=mem+2;

//Add parameters 10-21, all 1 byte long
for (mem=74; mem<88; mem++){
Configuration += EEPROM.read(mem);
Configuration += ",";
}
//Last parameter without comma
for (mem=88; mem<89; mem++){
Configuration += EEPROM.read(mem);
}

Configuration += "$"; 

}//End
