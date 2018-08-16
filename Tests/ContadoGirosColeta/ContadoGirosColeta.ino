#include "PonteHL9110.h"
#include "ContaGiros.h"
#include "RasBotArduino.h"

RasBotArduino robot(6,5,10,9);

ContaGiros cg; 


void setup() {
  Serial.begin(9600);
  cg.setup(A0,300);
  robot.moveF(100);
}

void testeContaGiros(){
  if ( cg.contaAte(20)) {
//    motorDC.setSpeedA(1,100);
      analogWrite(6,100);
  }
  else {
//    motorDC.stopMotorA();
    analogWrite(6,100);
  }
  
}

void testePicosPorTempo(){
//  motorDC.setSpeedA(1,110);
  unsigned long picos =  cg.girosPorTempo(10000); 
  Serial.println(picos); 
}

void testeVelocidadeAtual(){
  
  // tempo configurado para 1 segundo (1000 ms)
  double vel = cg.getVelocidade(500); 
  Serial.println(vel); 
}

void loop() {
  testeVelocidadeAtual();
  // Serial.println(analogRead(A0));
  // delay(100);  
}
