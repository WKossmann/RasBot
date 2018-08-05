#include "RasBot.h"
#include <wiringPi.h>

int main(){

    RasBot robot;

    robot.moveF(100);
    delay(3000);
    robot.turnL(30);
    delay(3000);
    robot.stop();
    
    return 0;

}