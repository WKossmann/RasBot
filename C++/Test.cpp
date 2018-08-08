#include "RasBot.h"


int main(){

    RasBot robot;
    robot.setPorts(1,36,33,35);

    robot.moveB(400);
    robot.turnL(400);
    robot.moveF(420);
    robot.turnR(421);

    return 0;

}