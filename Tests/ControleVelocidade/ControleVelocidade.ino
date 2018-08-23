#include "ContaGiros.h"
#include "RasBotArduino.h"

RasBotArduino robot(6,5,9,10);
ContaGiros cgD, cgE; 

unsigned long tempoAux = 0;

float pwm_inicial = 100;
unsigned long dt = 300;

float pwmE;
float eE, pvE, spE = 30;
float KpE = 1;

float pwmD;
float eD, pvD, spD = 30;
float KpD = 1;

void setup() {
  Serial.begin(9600);
  cgD.setup(A0,300);
  cgE.setup(A1,300);
  robot.moveF(pwm_inicial);
  cgD.getVelocidade(300);
  cgE.getVelocidade(300);
  pwmE = pwmD = pwm_inicial;
  tempoAux = millis();
}

void loop() {
  
  cgE.getVelocidade(300);
  cgD.getVelocidade(300);

  // if(millis()-tempoAux > dt){
  //   tempoAux = millis();

  //   pvD = cgD.getVelocidade(300);
  //   eD = spD-pvD;
  //   pwmD = pwmD + eD*KpD;
  //   if(pwmD>=255){
  //     pwmD=255;
  //   }

  //   pvE = cgE.getVelocidade(300);
  //   eE = spE-pvE;
  //   pwmE = pwmE + eE*KpE;
  //   if(pwmE>=255){
  //     pwmE=255;
  //   }

  //   robot.moveI(pwmE,pwmD);
  //   Serial.print(pvE);
  //   Serial.print(',');
  //   Serial.print(pwmE);
  //   Serial.print(',');
  //   Serial.print(spE);
  //   Serial.print(',');
  //   Serial.print(pvD);
  //   Serial.print(',');
  //   Serial.print(pwmD);
  //   Serial.print(',');
  //   Serial.println(spD);
  // }

  Serial.println(cgD.getVelocidade(100));

  // Teste limiar sensor:
  // robot.moveF(150);
  // Serial.println(analogRead(A1));
  // delay(100);
}
