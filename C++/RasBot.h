#ifndef RASBOT_H
#define RASBOT_H

// Coment this line to work on RPi, only difine this if you are coding on another device:
#define CHECK_CODE_OUTSIDE_RASP 
// Define this if you want to see debug mensages:
#define PRINT_DEBUG 


#ifndef CHECK_CODE_OUTSIDE_RASP
#include <WiringPi.h>
#endif
#ifdef PRINT_DEBUG
#include <iostream>
#endif

class RasBot{
public:
    RasBot();
    RasBot(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port);
    ~RasBot();

    bool setPorts(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port);

    void moveF(int relative_velocity); 
    void moveB(int relative_velocity);
    void turnL(int relative_velocity);
    void turnR(int relative_velocity);

    void motorL(int direction, int relative_velocity);
    void motorR(int direction, int relative_velocity);

private:
    int m_LF, m_LB, en_L;
    int m_RF, m_RB, en_R;
};

#endif