
//Bibliotheken für Gyro-Sensor
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <EEPROM.h>

// end license header
//
// This sketch is a good place to start if you're just getting started with
// Pixy and Arduino.  This program simply prints the detected object blocks
// (including color codes) through the serial console.  It uses the Arduino's
// ICSP SPI port.  For more information go here:
//
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//

// Uncomment one of these to enable another type of serial interface
#define I2C
//#define UART
//#define SPI_SS

#ifdef I2C

#include <Pixy2I2C.h>
Pixy2I2C pixy;

#else
#ifdef UART

#include <Pixy2UART.h>
Pixy2UART pixy;

#else
#ifdef SPI_SS

#include <Pixy2SPI_SS.h>
Pixy2SPI_SS pixy;

#else

#include <Pixy2.h>
Pixy2 pixy;

#endif
#endif
#endif

//PIXY
int i;
int XTor;
int YTor;
int XStandort;
int YStandort;
int XEnde;
int YEnde;
int TorRichtung;


//Knöpfe
int K1 = 23;

//Erstellen eines Obketes der Klasse Adafruit_BNO055 mit Namen gyro
Adafruit_BNO055 gyro = Adafruit_BNO055(55, 0x28);
double alterWinkel, minus, alpha, rot, Rot;


//Lichtschranke
constexpr int  LA17 = A12;

//IR
int SEbest;


//Motoren
const int AnzahlMotoren = 4;
int Mot_Pin_FW[AnzahlMotoren] = {6, 3, 30, 9};
int Mot_Pin_RW[AnzahlMotoren] = {4, 1, 10, 7};
int Mot_Pin_PWM[AnzahlMotoren] = {5, 2, 29, 8};

int Motor_Wert[AnzahlMotoren];

constexpr byte mH = 0, mR = 2, mL = 3, Dribbler = 1;

//Multiplexa
constexpr int MuxSig0 = 38;
constexpr int MuxSig1 = 37;
constexpr int MuxSig2 = 36;
constexpr int MuxSig3 = 35;
constexpr int Signal3 = A22;


double richtung , geschw , drehung;




void setup() {
  Serial.begin(115200);
  Serial.print("Starting...\n");
  if (!gyro.begin()) {       //wird der gyro nicht erkannt: Programm stoppt
    Serial.print("Kein Gyro erkannt");
    abort();
  }


  pixy.init();
  gyro.begin(8);
  Wire.begin();

  pinMode(Mot_Pin_FW[0], OUTPUT);
  pinMode(Mot_Pin_RW[0], OUTPUT);

  pinMode(Mot_Pin_FW[1], OUTPUT);
  pinMode(Mot_Pin_RW[1], OUTPUT);

  pinMode(Mot_Pin_FW[2], OUTPUT);
  pinMode(Mot_Pin_RW[2], OUTPUT);

  pinMode(Mot_Pin_FW[3], OUTPUT);
  pinMode(Mot_Pin_RW[3], OUTPUT);


  pinMode(K1, INPUT_PULLUP);

  pinMode(MuxSig0, OUTPUT);
  pinMode(MuxSig1, OUTPUT);
  pinMode(MuxSig2, OUTPUT);
  pinMode(MuxSig3, OUTPUT);
}





void loop() {
 if (!pixy.ccc.getBlocks()) {
    compass();
  }
  if (pixy.ccc.getBlocks()) {
    Pixy();
  }
  //Lichtschranke();
  infrarotlesen();
  infrarotverarbeiten();
  SchussSetzen();
  Motor();
}
