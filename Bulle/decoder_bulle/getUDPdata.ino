void getUDPdata() {
  // if there's data available, read a packet
    int packetSize = Udp.parsePacket();
  if (packetSize) {
    // read the packet into packetBufffer
    int n = Udp.read(packetBuffer, 20);
    packetBuffer[n] = 0;
    // Kolla om det är ett giltigt meddelande, dvs första tecknet=="I"
//int("packetBuffer ");
//intln(packetBuffer);

    char inledning = packetBuffer[0];
    String Inledning(inledning);
    if (Inledning == "I") {
      //separera ut ID
      String ID = "";
      int t = 1;
      while (isDigit(packetBuffer[t])) {
        ID = ID + packetBuffer[t];
        t++;
      }
      int id = ID.toInt();

      //Kolla om meddelandet är till eget ID
      if (id == myID) {  //Separera bar ut meddelande om det är till detta ID
                         //Nollställ ID
        id = 0;
        //titta om det är hastighet eller funktionsmeddelande

        char typ = packetBuffer[t];
        String ordertyp(typ);
        t++;
        String param1 = "";
        while (isDigit(packetBuffer[t])) {
          param1 = param1 + packetBuffer[t];
          t++;
        }
        //int(ordertyp);
        //om hastighetsmeddelande
        if (ordertyp == "H") {                                 // separear ut hastighet, riktning och meddelandeid
          if (0 == NSphase && 0 == NSRphase && Pphase == 0) {  //ändra bara om inte i automatkörning
            throttle_speed = param1.toInt();
            //adjust for set shunting
            if (shunting == true) {
              throttle_speed = (throttle_speed * Shuntingspeed) / 100;
            }
            String riktning = "";
            t++;
            riktning = packetBuffer[t];
            set_direction = riktning.toInt();
            t = t + 2;
            Seq = "";

            while (isDigit(packetBuffer[t])) {
              Seq = Seq + packetBuffer[t];
              t++;
            }
            //int("mottaget seq ");
            //int(Seq);
          }
        }                       //slut hanterat ordertyp H
        if (ordertyp == "F") {  //om Funktionsmeddelande
                                // separear ut funktion och meddelandeid
          int Funktionstangenter = param1.toInt();
          if (Funktionstangenter != lastparam1) {
            for (int f = 0; f < 29; f++) {
              FunctionKey[f] = 1;
              long int mask = pow(2, f);
              if ((Funktionstangenter & mask) == 0) FunctionKey[f] = 0;
            }  //slut uppdatering av spegelarea
            lastparam1 = Funktionstangenter;
            t++;
            Seq = "";
            while (isDigit(packetBuffer[t])) {
              Seq = Seq + packetBuffer[t];
              t++;
            }
            byte d = 0;
          }  //slut hanterat funktionstangenter om ändrat
          //int("mottaget seq ");
          //int(Seq);
        }  //slut hantering ordertyp F
           //Skicka Ack på mottaget meddelande
        int answer = Seq.toInt();
        //int("  returnerat seq ");
        //intln(answer);
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
        Udp.print(answer);
        Udp.endPacket();
        Seq = "";

      }  //slut på hantering av eget ID
    }    //Slut habtering av giltigt meddelande
  }      //Slut hanterat alla inkomna meddelanden
}  //slut rutin getUDPdata
