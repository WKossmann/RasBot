#include "PonteHL9110.h"
#include "ContaGiros.h"
#include "RasBotArduino.h"

RasBotArduino robot(6,5,10,9);
ContaGiros cg; 



unsigned long tempoAux = 0;
int pwm = 75;
double vel;
bool stop_ = true;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if(Serial.available()){
    char rd = Serial.read();
    if(rd == '1'){
      stop_ = false;
      cg.setup(A1,300);
      robot.moveF(pwm);
    }
  }

  //Teste pwmxvel:
  if(!stop_){
    vel = cg.getVelocidade(700);  
  }
  if(!stop_ && millis()-tempoAux > 800){
    tempoAux = millis();
    Serial.print(pwm);
    Serial.print(", ");
    Serial.println(vel);
    pwm +=  10;
    if(pwm >= 255){
      pwm = 80;
      robot.moveF(pwm);
    }else{
      robot.moveF(pwm);
    }
  }

//   Teste limiar sensor:
//   robot.moveF(150);
//   Serial.println(analogRead(A1));
//   delay(100);
}
