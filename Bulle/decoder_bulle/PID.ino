/*
/*
//from http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/
PIDCompute(void)
{
  /*   if(!inAuto) return;
     unsigned long now = millis();
     int timeChange = (now - lastTime);
     if(timeChange>=SampleTime)
     {*/
  /*Compute all the working error variables
  error = desired_speed - read_speed;
  ITerm += (ki * error);
  if (ITerm > outMax) ITerm = 1023;
  else if (ITerm < 0) ITerm = 0;
  double dInput = (read_speed - lastInput);

  /*Compute PID Output
  //current_PWM = current_PWM +((kp * error) + ITerm - (kd * dInput));
  current_PWM = current_PWM +(kp * error);
  if (current_PWM > outMax) current_PWM = outMax;
  else if (current_PWM < outMin) current_PWM = outMin;

  /*Remember some variables for next time
  lastInput = read_speed;
  //   lastTime = now;
  //   }
}

void SetPIDTunings(double Kp, double Ki, double Kd)
{
  kp = Kp;
  ki = Ki * SampleTime;
  kd = Kd / SampleTime;
}

/*void SetSampleTime(int NewSampleTime)
  {
   if (NewSampleTime > 0)
   {
      double ratio  = (double)NewSampleTime
                      / (double)SampleTime;
      ki *= ratio;
      kd /= ratio;
      SampleTime = (unsigned long)NewSampleTime;
   }
  }

  void SetOutputLimits(double Min, double Max)
  {
   if(Min > Max) return;
   outMin = Min;
   outMax = Max;

   if(Output > outMax) Output = outMax;
   else if(Output < outMin) Output = outMin;

   if(ITerm> outMax) ITerm= outMax;
   else if(ITerm< outMin) ITerm= outMin;
  }
*/
/*
void SetMode(int Mode)
{
  bool newAuto = (Mode == AUTOMATIC);
  if (newAuto && !inAuto)
  { /*we just went from manual to auto
    Initialize();
  }
  inAuto = newAuto;
}
*/
/*
void Initialize()
{
  lastInput = Input;
  ITerm = Output;
  if (ITerm > outMax) ITerm = outMax;
  else if (ITerm < outMin) ITerm = outMin;
}
*/
