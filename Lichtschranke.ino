int zeit_Schuss;
/*void Lichtschranke() {
  if (analogRead(A12) <= 14) {
    schuss();
  }
  }*/

void schuss()
{
  constexpr int totzeit = 1500;
  if (millis() > (totzeit + zeit_Schuss))
  {
    zeit_Schuss = millis();
   // Serial.println(zeit_Schuss);
  }
}


void SchussSetzen()
{
  if ((millis() >= zeit_Schuss ) && (millis() < (zeit_Schuss + 50)))
  {
    Motor_Wert[Dribbler] = 255;
  }
  else
  {
    Motor_Wert[Dribbler] = 0;
  }
}
