void Motor() {
  double bg = (richtung / 180.0) * PI;
  double x = cos(bg) * -255, y = sin(bg) * 255;


  Motor_Wert[mR] = ((x / 3)  - (y / sqrt(3))) * 0.075 * geschw * 1 + drehung; //*2 //0.075
  Motor_Wert[mL] = ((x / 3) + (y / sqrt(3))) * 0.075 * geschw * 1 + drehung; //0.1125
  Motor_Wert[mH] = -((((2 * x) / 3) * 0.075) * geschw * 1 - drehung);



  if (Motor_Wert[0] > 0) {
    digitalWrite(Mot_Pin_FW[0], LOW);
    digitalWrite(Mot_Pin_RW[0], HIGH);
    analogWrite(Mot_Pin_PWM[0], abs(Motor_Wert[0]));
  }
  if (Motor_Wert[0] < 0) {
    digitalWrite(Mot_Pin_FW[0], HIGH);
    digitalWrite(Mot_Pin_RW[0], LOW);
    analogWrite(Mot_Pin_PWM[0], abs(Motor_Wert[0]));
  }
  if (Motor_Wert[0] == 0) {
    digitalWrite(Mot_Pin_FW[0], HIGH);
    digitalWrite(Mot_Pin_RW[0], HIGH);
    analogWrite(Mot_Pin_PWM[0], 255);
  }
  if (Motor_Wert[1] > 0) {
    digitalWrite(Mot_Pin_FW[1], LOW);
    digitalWrite(Mot_Pin_RW[1], HIGH);
    analogWrite(Mot_Pin_PWM[1], abs(Motor_Wert[1]));
  }
  if (Motor_Wert[1] < 0) {
    digitalWrite(Mot_Pin_FW[1], HIGH);
    digitalWrite(Mot_Pin_RW[1], LOW);
    analogWrite(Mot_Pin_PWM[1], abs(Motor_Wert[1]));
  }
  if (Motor_Wert[1] == 0) {
    digitalWrite(Mot_Pin_FW[1], LOW);
    digitalWrite(Mot_Pin_RW[1], LOW);
    analogWrite(Mot_Pin_PWM[1], 255);
  }
  if (Motor_Wert[2] > 0) {
    digitalWrite(Mot_Pin_FW[2], LOW);
    digitalWrite(Mot_Pin_RW[2], HIGH);
    analogWrite(Mot_Pin_PWM[2], abs(Motor_Wert[2]));
  }
  if (Motor_Wert[2] < 0) {
    digitalWrite(Mot_Pin_FW[2], HIGH);
    digitalWrite(Mot_Pin_RW[2], LOW);
    analogWrite(Mot_Pin_PWM[2], abs(Motor_Wert[2]));
  }
  if (Motor_Wert[2] == 0) {
    digitalWrite(Mot_Pin_FW[2], HIGH);
    digitalWrite(Mot_Pin_RW[2], HIGH);
    analogWrite(Mot_Pin_PWM[2], 255);
  }
  if (Motor_Wert[3] > 0) {
    digitalWrite(Mot_Pin_FW[3], LOW);
    digitalWrite(Mot_Pin_RW[3], HIGH);
    analogWrite(Mot_Pin_PWM[3], abs(Motor_Wert[3]));
  }
  if (Motor_Wert[3] < 0) {
    digitalWrite(Mot_Pin_FW[3], HIGH);
    digitalWrite(Mot_Pin_RW[3], LOW);
    analogWrite(Mot_Pin_PWM[3], abs(Motor_Wert[3]));
  }
  if (Motor_Wert[3] == 0) {
    digitalWrite(Mot_Pin_FW[3], LOW);
    digitalWrite(Mot_Pin_RW[3], LOW);
    analogWrite(Mot_Pin_PWM[3], 255);
  }
}
