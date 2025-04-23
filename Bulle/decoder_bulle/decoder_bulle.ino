/*
  Implementation for For WiFi control of locomotive by UDP messages sent from modified DCC++EX command station

  Change log:
  2021-08-28   ver 1.0 First version based on AP variant 1.6
  2021-08-30   ver 1.1 Configuration in AP mode added
  2021-09-20   ver 1.2 OTA added
  2021-10-01   ver 1.3 PID added
  2021-10-19   ver 1.4 Steam puff updated
  2022-07-14   ver 1.5 Acknowleged added on received UDP package
  2022-09-01   ver 1.6 Acknowleged changed to return accepted message
  2024-08-19   ver 3.0 Change configuration from AT mode to webserver

*/
const String ver = "3.0";
/*

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include "Config.h"
#include <WiFiClient.h>
//#include <ESP8266WiFiMulti.h>   // Include the Wi-Fi-Multi library
#include <ESP8266mDNS.h>  // Include the mDNS library
#include <Dns.h>
//ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

//#include <ESP.h>

WiFiServer server(23);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  //intln("");
  EEPROM.begin(512);
  Getsettings();
 
  String HostID = "Lok" + String(myID);  //create Hostname from read ID
  WiFi.setHostname(HostID.c_str());
  ArduinoOTA.setHostname(HostID.c_str());
 //OTAsetup();
  WiFi.mode(WIFI_STA);
  //SSID och Password till lokala nätverket, anslut
  STASSID = ssid;
  STAPSK = password;
  WiFi.begin(STASSID, STAPSK);

  //Initialize I/O
  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(OUT1, OUTPUT);
  digitalWrite(OUT1, LOW);
  pinMode(OUT2, OUTPUT);
  digitalWrite(OUT2, LOW);
  pinMode(OUT3, OUTPUT);
  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, HIGH);
  pinMode(OUT4, OUTPUT);
  digitalWrite(OUT4, LOW);
  pinMode(OUT5, OUTPUT);
  digitalWrite(OUT5, LOW);
  pinMode(OUT6, OUTPUT);
  digitalWrite(OUT6, LOW);
  pinMode(IN, INPUT_PULLUP);

  //check if there is a configuration done and if so read from EEprom


  //analogWriteFreq(pwmfrq);
  analogWriteFreq(10000);

  //analogWriteFreq(10000);
  WiFi.setOutputPower(20.5);  // this sets wifi to highest power
  //Set PID parameters
  //SetTunings(double Kp, double Ki, double Kd)

  kp = 0.025;
  ki = 0.015;
  kd = 0.09;

  long starttid = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    //int(".");
  }
  //intln(".");
  //intln("NTJ DDC-UDP Locomotive control ver " + ver);
  //int("IP address: ");
  //intln(WiFi.localIP());
  Udp.begin(localPort);
  server.begin();
  MDNS.begin(HostID.c_str());
  //int("Namn: ");
  //intln(HostID.c_str());
}

void loop() {
  MDNS.update();
  //Check for software update only at standstill
  if (0 == current_PWM) {
    //MDNS.update();
    ArduinoOTA.handle();
  }
  if (server.hasClient()) {
    client = server.accept();
    //intln("New client");
  }
  //client.println("Anslutning windows");
  if (client.available()) {
    Data = client.readString();
    if (Data.length() > 0) //intln(Data);
    client.flush();
    Programming();
  }

  //Check if there is UDP message to process
  getUDPdata();

  //Do timebased repetition of routines
  // (25ms) SampleTime repeat:
  if (millis() >= last25run + SampleTime) {
    last25run = millis();
    every25ms();
  }
  // 50ms repeat:
  if (millis() >= last50run + 50) {
    last50run = millis();
    every50ms();
  }
  // 100ms repeat:
  if (millis() >= last100run + 100) {
    last100run = millis();
    every100ms();
  }
  // 400ms repeat:
  if (millis() >= last400run + 200) {
    last400run = millis();
    every400ms();
  }
  // 1000ms (sek) repeat:
  if (millis() >= last1000run + 1000) {
    last1000run = millis();
    every1000ms();
  }

}  // Slut loop
