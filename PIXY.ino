void Pixy()
{
  int i;
  // grab blocks!
  pixy.ccc.getBlocks();


  XTor =  pixy.ccc.blocks[i].m_x;
  YTor =  pixy.ccc.blocks[i].m_y;


  XStandort = 240;
  YStandort = 0;

  XEnde = XTor - XStandort;
  YEnde = YTor - YStandort;


  TorRichtung = (((atan2(XEnde, YEnde)) * 180 / PI) + 130.75);

  //Serial.println(TorRichtung);
  //delay(100);

  if (TorRichtung <= 70) {
    drehung = -25;
  }

  if (TorRichtung >= 110) {
    drehung = 25;
  }

  if (TorRichtung > 65 && TorRichtung < 115) {
    drehung = 0;
    schuss();
  }

}
//HINTEN = 270
//VORNE = 90
//RECHTS = 180
//LINKS = 0/360
