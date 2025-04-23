/*
   Config.h

*/

/* Maximum WiFi clients that can be connected to WiThrottle */

String Configstring = "";         // a String to hold incoming data
boolean configmode = false;
int Inaddr;
String Configuration;
String Data;


//Main loop declarations
unsigned long last25run = 0;
unsigned long last50run = 0;
unsigned long last100run = 0;
unsigned long last400run = 0;
unsigned long last1000run = 0;
/* Define Control board I/O signals */
#define OUT1  D7 /*Define which GPIO corresponds to which output on the board*/
#define OUT2  D8
#define OUT3  D4
#define OUT4  D3
#define OUT5  D2
#define OUT6  D1
#define PWM  D5 /* Defines the GPIO for the PWM transistor control*/
#define DIR  D6 /* Defines the GPIO for the direction relay control*/
#define IN  D0 /* Defines the GPIO for the LED on the control board*/


long throttle_speed = 0; //0 to 126
int set_direction = 1; //1=forwrd 0=reverse
String namn;

long last=0;
long lastprint=0;

//getUDPdata declarations

String STASSID = "NTJ1";
String STAPSK =  "NTJNTJ01";
int packetSize=0;

int myID = 111;
String Seq;

unsigned int localPort = 8888;      // local port to listen on
long lastparam1 = 0;
byte FunctionKey[30];

// buffer for sending data
char packetBuffer[20 + 1]; //buffer to hold incoming packet,

WiFiUDP Udp;

//Variabler lagrade i EEprom med defaultvärden angivna här
byte acceleration_time = 10; // FSet the time in seconds it should take for the locomotive to accelerate from standstill to full speed
byte deceleration_time = 10; //Set the time in seconds it should take for the locomotive to stop from full speed
int pwmfrq = 300;
int zero_speed = 10; //Set the PWM value where the locomotive, without load,starts to move
int fullspeed = 100;
int slowspeed = 75;
int halfspeed = 50;
int Shuntingspeed = 30;
int max_pulserate = 50;    //time between pulses in ms. If set to 0 the output will be only ON/OFF
int min_pulserate = 1000; //time between pulses in ms.If set to 0 the output will be only ON/OFF
int pulselength = 3;      //length of the sound generating puls relative the time between pulses in (1/(pulselength*actual pulselength))
int startwhistle = 20;
int approachwhistle = 30;
int smoke_timer = 0;
int creepspeed = 10;
int mindwell = 60;
int maxdwell = 240;
String ssid = "Ny_dekoder";
String loco_name = "Nytt_lok";
String password = "12345678";
int port = 44;
String hostn = "Ny_thserver";


//25ms declarations
boolean EMS = false;
boolean EMS_stopped = false;
float set_speed = 0;
float desired_speed = 0;
float current_PWM = 0;
float read_speed = 0;
float reglerfaktor = 40;
//int fixedpwm=50;

//50ms declarations
byte NSphase = 0;
byte NSRphase = 0;

//100ms declarations
byte NWphase = 0;
long nextwhistle = 0;


//400ms declarations
boolean NEXTSTATION = false;
boolean NEXTSTATIONREMOTE = false;
boolean PENDULUM = false;
boolean NEXTTIMER = false;
boolean sound = false;
boolean smoke = false;
boolean shunting = false;

//1000ms declarations
int smokeon = 0;

//Pendulum declarations
byte Pphase = 0;
long next = 0;
long startdwell = 0;
long dwelltime = 0;

/*PID working variables*/
unsigned long lastTime;
//double Input, Setpoint; Output, 
float ITerm, lastInput;
float kp, ki, kd;
int SampleTime = 25; //ms between samples
//double outMin, outMax;
//bool inAuto = false;
float error =0;
float dInput=0;

byte done=1;
long lastinc=0;
 
#define MANUAL 0
#define AUTOMATIC 1
