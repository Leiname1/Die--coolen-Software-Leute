//IR-Sensor
int IR[16];
int IRbest;


int lesenMultiplexerOben(int s1, int s2, int s3, int s4) {  //Verkürzung Auslesen
  digitalWrite(MuxSig0, s1);
  digitalWrite(MuxSig1, s2);
  digitalWrite(MuxSig2, s3);
  digitalWrite(MuxSig3, s4);
  return analogRead(Signal3);
}





void infrarotlesen() {
  IR[0] = lesenMultiplexerOben(0, 0, 0, 0);
  IR[1] = lesenMultiplexerOben(1, 0, 0, 0);
  IR[2] = lesenMultiplexerOben(0, 1, 0, 0);
  IR[3] = lesenMultiplexerOben(1, 1, 0, 0);
  IR[4] = lesenMultiplexerOben(0, 0, 1, 0);
  IR[5] = lesenMultiplexerOben(1, 0, 1, 0);
  IR[6] = lesenMultiplexerOben(0, 1, 1, 0);
  IR[7] = lesenMultiplexerOben(1, 1, 1, 0);
  IR[8] = lesenMultiplexerOben(0, 0, 0, 1);
  IR[9] = lesenMultiplexerOben(1, 0, 0, 1);
  IR[10] = lesenMultiplexerOben(0, 1, 0, 1);
  IR[11] = lesenMultiplexerOben(1, 1, 0, 1);
  IR[12] = lesenMultiplexerOben(0, 0, 1, 1);
  IR[13] = lesenMultiplexerOben(1, 0, 1, 1);
  IR[14] = lesenMultiplexerOben(0, 1, 1, 1);
  IR[15] = lesenMultiplexerOben(1, 1, 1, 1);
}

void infrarotverarbeiten() {
  SEbest = -1;
  IRbest = 1000;
  for (int x = 0; x < 16; x++) {
    if (IR[x] < IRbest) {
      IRbest = IR[x];
      SEbest = x;
    }
  }
  if (IRbest <= 540) {
    switch (SEbest) {
      case 0: richtung = 180; break;
      case 1: richtung = 202.5; break;
      case 2: richtung = 225; break;
      case 3: richtung = 247.5; break;                                                                  //HINTEN = 270
      //VORNE = 90
      //RECHTS = 180
      //LINKS = 0/360
      case 4: richtung = 270; break;
      case 5: richtung = 315; break;
      case 6: richtung = 337.5; break;
      case 7: richtung = 75; break;
      case 8: richtung = 90; break;
      case 9: richtung = 105; break;
      case 10: richtung = 202.5; break;
      case 11: richtung = 225; break;
      case 12: richtung = 270; break;
      case 13: richtung = 292.5; break;
      case 14: richtung = 315; break;
      case 15: richtung = 337.5; break;
    }
   

    geschw = 6;
  }

  else if (IRbest > 540 && IRbest < 1000) {
    switch (SEbest) {
      case 0: richtung = 270; break;
      case 1: richtung = 247.5; break;
      case 2: richtung = 225; break;
      case 3: richtung = 337.5; break;
      case 4: richtung = 0; break;
      case 5: richtung = 25.5; break;
      case 6: richtung = 45; break;
      case 7: richtung = 112.5; break;
      case 8: richtung = 90; break;
      case 9: richtung = 67.5; break;
      case 10: richtung = 135; break;
      case 11: richtung = 157.5; break;
      case 12: richtung = 180; break;
      case 13: richtung = 202.5; break;
      case 14: richtung = 315; break;
      case 15: richtung = 292.5; break;
    }
    geschw = 9;
  }
  else {
    SEbest = -1;
    richtung = -1;
    geschw = 0;
  }
  //Serial.println(IR[0]);
  //delay(10);
}
