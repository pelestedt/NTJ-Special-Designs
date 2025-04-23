void OTAsetup(){
  // //intln("Booting");
 
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
 // namn="Lok"+loco_name;
  //ArduinoOTA.setHostname(namn.c_str());

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    // //intln("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    // //intln("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    // //intf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    // //intf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      // //intln("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      // //intln("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      // //intln("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      // //intln("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      // //intln("End Failed");
    }
  });
  ArduinoOTA.begin();
  // //intln("Ready");
  // //int("IP address: ");
  // //intln(WiFi.localIP());
}
