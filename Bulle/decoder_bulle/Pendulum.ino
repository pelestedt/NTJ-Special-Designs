void Pendulum(){
  
//Set positive travelling direction and start
if (0 == Pphase){Pphase=1; set_direction = 1;} 

//Give start whistle for startwhistle define time.
if(1==Pphase){digitalWrite(OUT4, HIGH); next=millis()+startwhistle*100; Pphase=2; NEXTTIMER=true;}
if(2==Pphase && millis()>=next){digitalWrite(OUT4, LOW); NEXTTIMER=false; Pphase=3;}

//Creep over first magnet for three seconds and then increase speed to slow
if(3==Pphase){throttle_speed=creepspeed; next=millis()+3000; Pphase=4;}
if(4==Pphase && millis()>next && HIGH==digitalRead(IN)){digitalWrite(OUT4, LOW);throttle_speed=slowspeed; Pphase=5;}

//Search for next magnet and increase speed to halfspeed      
if(5==Pphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; next=millis()+3000; Pphase=6;}

//Clear the magnet for three seconds
if(6==Pphase && millis()>next){Pphase=7;}

//find station border mangnet and increase speed to fullspeed     
if(7==Pphase && LOW==digitalRead(IN)){throttle_speed=fullspeed; next=millis()+3000; Pphase=8;}

//Clear the magnet for three seconds
if(8==Pphase && millis()>next){Pphase=9;}       

//Find first magnet at next station, slow down to 1/2 speed and whistle two times
if(9==Pphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;Pphase=10; NEXTTIMER=true;}
if(10==Pphase && millis()>next){digitalWrite(OUT4, LOW); next=millis()+approachwhistle*100;Pphase=11;}
if(11==Pphase && millis()>next){digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;Pphase=12;}
if(12==Pphase && millis()>next){digitalWrite(OUT4, LOW); Pphase=13; NEXTTIMER=false;}

//Search for next magnet and set slowspeed
if(13==Pphase && LOW==digitalRead(IN)){throttle_speed=slowspeed; next=millis()+3000;Pphase=14;}

//Clear the magnet for three seconds
if(14==Pphase && millis()>next){Pphase=15;}

//Search for next magnet and set creepspeed
if(15==Pphase && LOW==digitalRead(IN)){throttle_speed=creepspeed; next=millis()+3000;Pphase=16;}

//Clear the magnet for three seconds
if(16==Pphase && millis()>next){Pphase=17;}

//Find the stop magnet and move until it releases
if(17==Pphase && LOW==digitalRead(IN)){Pphase=18;}

//Stop when the stop magnet is passed
if(18==Pphase && HIGH==digitalRead(IN)){throttle_speed=0; Pphase=19; startdwell=millis();dwelltime=random(mindwell,maxdwell);}

// Wait until time elapsed
if(19==Pphase && millis()> startdwell+ (10000*dwelltime)){Pphase=20; set_direction = 0;}// Change travelling direction 0== reverse

// Repeat above

//Give start whistle for startwhistle define time.
if(20==Pphase){digitalWrite(OUT4, HIGH); next=millis()+startwhistle*100; Pphase=21; NEXTTIMER=true;}
if(21==Pphase && millis()>=next){digitalWrite(OUT4, LOW); NEXTTIMER=false; Pphase=22;}

//Creep over first magnet for three seconds and then increase speed to slow
if(22==Pphase){throttle_speed=creepspeed; next=millis()+3000; Pphase=23; }
if(23==Pphase && millis()>next && HIGH==digitalRead(IN)){digitalWrite(OUT4, LOW);throttle_speed=slowspeed; Pphase=25;}

//Search for next magnet and increase speed to halfspeed      
if(25==Pphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; next=millis()+3000; Pphase=26;}

//Clear the magnet for three seconds
if(26==Pphase && millis()>next){Pphase=27;}

//find station border mangnet and increase speed to fullspeed     
if(27==Pphase && LOW==digitalRead(IN)){throttle_speed=fullspeed; next=millis()+3000; Pphase=28;}

//Clear the magnet for three seconds
if(28==Pphase && millis()>next){Pphase=29;}       

//Find first magnet at next station, slow down to 1/2 speed and whistle two times
if(29==Pphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;Pphase=30; NEXTTIMER=true;}
if(31==Pphase && millis()>next){digitalWrite(OUT4, LOW); next=millis()+approachwhistle*100;Pphase=32;}
if(32==Pphase && millis()>next){digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;Pphase=33;}
if(33==Pphase && millis()>next){digitalWrite(OUT4, LOW); Pphase=34; NEXTTIMER=false;}

//Search for next magnet and set slowspeed
if(34==Pphase && LOW==digitalRead(IN)){throttle_speed=slowspeed; next=millis()+3000;Pphase=35;}

//Clear the magnet for three seconds
if(35==Pphase && millis()>next){Pphase=36;}

//Search for next magnet and set creepspeed
if(36==Pphase && LOW==digitalRead(IN)){throttle_speed=creepspeed; next=millis()+3000;Pphase=37;}

//Clear the magnet for three seconds
if(37==Pphase && millis()>next){Pphase=38;}

//Find the stop magnet and move until it releases
if(39==Pphase && LOW==digitalRead(IN)){Pphase=40;}

//Stop when the stop magnet is passed
if(40==Pphase && HIGH==digitalRead(IN)){throttle_speed=0; Pphase=41; startdwell=millis();dwelltime=random(mindwell,maxdwell);}

// Wait until time elapsed
if(41==Pphase && millis()> startdwell+ (10000*dwelltime)){Pphase=0; set_direction = 1;}// Change travelling direction 1== forward

// Start over


  
  
  }//End Pedulum()
