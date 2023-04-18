void compass() {

  sensors_event_t orientationData;
  sensors_event_t angVelocityData;
  gyro.getEvent(&angVelocityData,  Adafruit_BNO055::VECTOR_GYROSCOPE);
  gyro.getEvent(&orientationData,  Adafruit_BNO055::VECTOR_EULER);
  double winkel = orientationData.orientation.x;
  double rotationSpeed = angVelocityData.orientation.z;

  if (digitalRead(K1) == LOW) {
    minus = winkel ;
  }

  winkel = winkel - minus;
  //Serial.println(winkel);
  //delay(10);
  double  tWinkel1 = 356, tWinkel2 = 6;

  if (winkel > 180) {
    winkel = winkel - 360;
  }
  if (winkel < -180) {
    winkel = winkel + 360;

  }
  double p = -1.2;//-0.5
  double d = -4.9;//-1.5

  drehung = (p * winkel) - (d * rotationSpeed);

  //Serial.println(drehung);
  //delay(100);
  alpha = (winkel / 180) * PI;

  rot = drehung / 0.60;

}
