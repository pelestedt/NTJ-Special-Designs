void every50ms()
{
// code to be repeated every 50ms

/*HAndle spped increase and speed decrease
 *throttle_speed from the wifi control has a value from 0 through 126
 * This translates to an RPM feedback from 0 to 1024
 * Each step of throttle control is hence 1024/126
 * set_speed will then be throttle_speed*1024/126
 */           
 set_speed=throttle_speed*1021/126;
 if(set_speed>1021)set_speed=1021;

//set_speed is now the expected value we should read at the analogue input when moving with throttle_speed
//When the set_speed changes we do not want it to jump to the new value but ramp according to set acc and dec
//desired_speed is the speed value being ramped up or down

//Acceleratin, change current_speed towards set_speed if current_speed < set_speed (accelerate)
if(desired_speed<set_speed){
desired_speed=desired_speed+(1024/(acceleration_time*20));
//Also handle if the speed value is close to correct to avoid osscilation
if(abs(set_speed-desired_speed)<= (1024/(acceleration_time*20))) desired_speed=set_speed;
}
//change current_speed towards set_speed if current_speed > set_speed (decelerate)
if(desired_speed>set_speed){
  desired_speed=desired_speed-(1024/(acceleration_time*20));
//Also handle if the speed value is close to correct to avoid osscilation
if(abs(set_speed-desired_speed)<= (1024/(acceleration_time*20))) desired_speed=set_speed;  
  }

// //int(throttle_speed);//int(" / ");//int(set_speed);//int(" / ");//intln(desired_speed);



//Handle going to next station

if(NEXTSTATION==true){

//Give start whistle for startwhistle define time.
if(1==NSphase){digitalWrite(OUT4, HIGH); next=millis()+startwhistle*100; NEXTTIMER=true;NSphase=2;}
if(2==NSphase && millis()>=next){digitalWrite(OUT4, LOW); NEXTTIMER=false; NSphase=3;}

//Creep over first magnet for three seconds and then increase speed to slow
if(3==NSphase){throttle_speed=creepspeed; next=millis()+3000; NSphase=4; }
if(4==NSphase && millis()>next && HIGH==digitalRead(IN)){digitalWrite(OUT4, LOW);throttle_speed=slowspeed; NSphase=5;}

//Search for next magnet and increase speed to halfspeed 3 sek later      
if(5==NSphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; next=millis()+3000; NSphase=6;}

//Clear the magnet for three seconds
if(6==NSphase && millis()>next){NSphase=7;}

//find station border mangnet and increase speed to fullspeed     
if(7==NSphase && LOW==digitalRead(IN)){throttle_speed=fullspeed; next=millis()+3000; NSphase=8;}

//Clear the magnet for three seconds
if(8==NSphase && millis()>next){NSphase=9;}       

//Find first magnet at next station, slow down to 1/2 speed and whistle two times
if(9==NSphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;NSphase=10; NEXTTIMER=true;}
if(10==NSphase && millis()>next){digitalWrite(OUT4, LOW); next=millis()+approachwhistle*100;NSphase=11;}
if(11==NSphase && millis()>next){digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;NSphase=12;}
if(12==NSphase && millis()>next){digitalWrite(OUT4, LOW); NSphase=13; NEXTTIMER=false;}

//Search for next magnet and set slowspeed
if(13==NSphase && LOW==digitalRead(IN)){throttle_speed=slowspeed; next=millis()+3000;NSphase=14;}

//Clear the magnet for three seconds
if(14==NSphase && millis()>next){NSphase=15;}

//Search for next magnet and set creepspeed
if(15==NSphase && LOW==digitalRead(IN)){throttle_speed=creepspeed; next=millis()+3000;NSphase=16;}

//Clear the magnet for three seconds
if(16==NSphase && millis()>next){NSphase=17;}

//Find the stop magnet and move until it releases
if(17==NSphase && LOW==digitalRead(IN)){NSphase=18;}

//Stop when the stop magnet is passed
if(18==NSphase && HIGH==digitalRead(IN)){throttle_speed=0; NEXTSTATION=false; NSphase=0;}


}//End of Nextstation

//Handle Function key 11 going to next station on digital input
//int("NEXTSTATION==");//intln(NEXTSTATION);
if(NEXTSTATIONREMOTE==true){
//Wait for digital input to be set
if (LOW==digitalRead(IN) && 0 == NSRphase){NSRphase=1;} //Wait for digital input to be set

//Give start whistle for startwhistle define time.
if(1==NSRphase){digitalWrite(OUT4, HIGH); next=millis()+startwhistle*100; NSRphase=2; NEXTTIMER=true;}
if(2==NSRphase && millis()>=next){digitalWrite(OUT4, LOW); NEXTTIMER=false; NSRphase=3;}

//Creep over first magnet for three seconds and then increase speed to slow
if(3==NSRphase){throttle_speed=creepspeed; next=millis()+3000; NSRphase=4; }
if(4==NSRphase && millis()>next && HIGH==digitalRead(IN)){digitalWrite(OUT4, LOW);throttle_speed=slowspeed; NSRphase=5;}

//Search for next magnet and increase speed to halfspeed      
if(5==NSRphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; next=millis()+3000; NSRphase=6;}

//Clear the magnet for three seconds
if(6==NSRphase && millis()>next){NSRphase=7;}

//find station border mangnet and increase speed to fullspeed     
if(7==NSRphase && LOW==digitalRead(IN)){throttle_speed=fullspeed; next=millis()+3000; NSRphase=8;}

//Clear the magnet for three seconds
if(8==NSRphase && millis()>next){NSRphase=9;}       

//Find first magnet at next station, slow down to 1/2 speed and whistle two times
if(9==NSRphase && LOW==digitalRead(IN)){throttle_speed=halfspeed; digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;NSRphase=10; NEXTTIMER=true;}
if(10==NSRphase && millis()>next){digitalWrite(OUT4, LOW); next=millis()+approachwhistle*100;NSRphase=11;}
if(11==NSRphase && millis()>next){digitalWrite(OUT4, HIGH); next=millis()+approachwhistle*100;NSRphase=12;}
if(12==NSRphase && millis()>next){digitalWrite(OUT4, LOW); NSRphase=13; NEXTTIMER=false;}

//Search for next magnet and set slowspeed
if(13==NSRphase && LOW==digitalRead(IN)){throttle_speed=slowspeed; next=millis()+3000;NSRphase=14;}

//Clear the magnet for three seconds
if(14==NSRphase && millis()>next){NSRphase=15;}

//Search for next magnet and set creepspeed
if(15==NSRphase && LOW==digitalRead(IN)){throttle_speed=creepspeed; next=millis()+3000;NSRphase=16;}

//Clear the magnet for three seconds
if(16==NSRphase && millis()>next){NSRphase=17;}

//Find the stop magnet and move until it releases
if(17==NSRphase && LOW==digitalRead(IN)){NSRphase=18;}

//Stop when the stop magnet is passed
if(18==NSRphase && HIGH==digitalRead(IN)){throttle_speed=0; NSRphase=0;}

//END OF NEXT STATION REMOTE
}

//Continous Pendelum traffic
//Handle Function key 12, continous pendlum traffic
if(1==PENDULUM){ Pendulum();  }//Handle train in pendulum traffic
if(0==PENDULUM){Pphase=0;}

}// End of every 50ms
