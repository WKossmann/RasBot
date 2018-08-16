#include "Arduino.h"
#include "RasBotArduino.h"

RasBotArduino robot(6,5,10,9);

#define ENC_L_PORT A0
#define ENC_R_PORT A1

#define DISTANCE ((2*M_PI*6.6)/20.0)

bool last_state_l = 0, last_state_r = 0;
long int last_high_l = 0, last_high_r = 0;

double getSpeed(char side){
  int sensorRead;
  bool state;
  switch(side){
    case 'L':
      sensorRead = analogRead(ENC_L_PORT);
      if(sensorRead < 350){
        state = 1;
      }else{
        state = 0;
      }
      if(last_state_l == 0 && state == 1){
        last_state_l = state;
        unsigned long time_elapsed = millis() - last_high_l; //ms
        // Serial.println(time_elapsed);
        double speed = DISTANCE/(time_elapsed/1000.0);
        last_high_l = millis();
        return speed;
      }else{
        last_state_l = state;
      }
    break;
    case 'R':
      sensorRead = analogRead(ENC_R_PORT);
      if(sensorRead < 350){
        state = 1;
      }else{
        state = 0;
      }
      if(last_state_r == 0 && state == 1){
        last_state_r = state;
        unsigned long time_elapsed = millis() - last_high_r; //ms
        // Serial.println(time_elapsed);
        double speed = DISTANCE/(time_elapsed/1000.0);
        last_high_r = millis();
        return speed;
      }else{
        last_state_r = state;
      }
    break;
    default:

    break;
  }
}

void setup() {
  pinMode(ENC_L_PORT, INPUT);
  pinMode(ENC_R_PORT, INPUT);

  Serial.begin(9600);
}
void loop() {
  // robot.moveF(255);
  Serial.println(getSpeed('L'));
  // Serial.println(analogRead(ENC_L_PORT));
}
