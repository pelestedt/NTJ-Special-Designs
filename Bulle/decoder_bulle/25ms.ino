void every25ms()
{
// code to be repeated every 25ms
//turn the motor off
analogWrite(PWM,0);
//wait for the analogue input to stabalize
delay(3);
//read the value 4 times and make an average
int v1=analogRead(A0);
delay(1);
int v2=analogRead(A0);
delay(1);
int v3=analogRead(A0);

//turn motor on again
if(EMS==false)analogWrite(PWM,current_PWM);

int maxvolt=v1;
if(v2>v1)maxvolt=v2;
if(v3>maxvolt)maxvolt=v3;
int minvolt=v1;
if(v2<v1)minvolt=v2;
if(v3<minvolt)minvolt=v3;
read_speed=v1+v2+v3-maxvolt-minvolt;



if(1024==read_speed)read_speed=1023;

//make sure regulation of speed starts at "zero_speed"
//if(set_speed > 0 && current_PWM < zero_speed)current_PWM=zero_speed;

//regulate the PWM to get correct read_speed
//Trial with a PDI regulator
//Öka ki var 20e sekund
//if(millis()>lastinc+10000){ki=ki+0.001; lastinc=millis();}
/*
//PIDCompute();
  error = desired_speed - read_speed;
//  if(error>30)kp=
  ITerm += (ki * error);
  if (ITerm > 1022) ITerm = 1022;
  else if (ITerm < 0) ITerm = 0;
  dInput = (read_speed - lastInput);

  //Compute PID Output
  //current_PWM = current_PWM +((kp * error) + ITerm - (kd * dInput)); 
  current_PWM = current_PWM +(kp * error)+ ITerm - (kd * dInput);
  if (current_PWM > 1023) current_PWM = 1023;
  else if (current_PWM < 0) current_PWM = 0;
current_PWM = 20;
  //*Remember some variables for next time
  lastInput = read_speed;

*/
//*******************************
// current_PWM=current_PWM+((desired_speed-read_speed)/reglerfaktor);
// current_PWM=current_PWM+((desired_speed-read_speed)/(abs(desired_speed-read_speed)));
// current_PWM=set_speed;
/*
//if(desired_speed>read_speed){current_PWM=current_PWM+((desired_speed-read_speed)/reglerfaktor); }
if(desired_speed>read_speed){current_PWM=current_PWM+1; }
//or change +/-error divided by reglerfaktor to a proportional value??

//if(desired_speed<read_speed)current_PWM=current_PWM-((read_speed-desired_speed)/reglerfaktor);
if(desired_speed<read_speed)current_PWM=current_PWM-1;
//limit current_PWM to 1023
*/
if(desired_speed>read_speed){current_PWM=current_PWM+1; }
if(desired_speed<read_speed){current_PWM=current_PWM-1;}



//if(desired_speed>0 && current_PWM<100)current_PWM=40;
if(current_PWM>1023)current_PWM=1023;
if(desired_speed==0)current_PWM=0; 
//do not turn motor on if EMS, emergency stop, is active
//if(desired_speed>0){//int(desired_speed);//int(",");//int(read_speed);//int(",");//intln(current_PWM);}
  
if(EMS==false)analogWrite(PWM,int(current_PWM));



//if(EMS==true)analogWrite(PWM,0);
//if(EMS==true)set_speed = 0;
}
