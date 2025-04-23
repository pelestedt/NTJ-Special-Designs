void every1000ms()
{
  client.println("Anslutning från windows accepterad");
  // code to be repeated every 1000ms (every second)
  //Increment time the smoke generator has been on and turn it off after timeout
/*
//int(current_PWM);//int("  ");
//int(read_speed);//int(" error= ");
//int(error);//int("  ");//int(kp*error);
//int(" ki= ");//intln(int(ki*1000));
*/
 
  //Check that a time > 0 is set
  if (smoke_timer > 0) {
    // Check if smoke output is on increment smoke_timer and set button on throttle on
    if (FunctionKey[6] == true) {
      smokeon = smokeon + 1;
    }
    // Check if time has elapsed and if it has, reset timer and output
    if (smokeon > (smoke_timer * 60)) {
      digitalWrite(OUT6, LOW);
      FunctionKey[6] = false;
      smoke_timer = 0;
    }
    if (FunctionKey[6] == false) {
      digitalWrite(OUT6, LOW);
    }
  }
}
