#ifndef RasBotArduino_H
#define RasBotArduino_H

#include "Arduino.h"

// Coment this line with don't want debug mensages:
// #define PRINT_DEBUG

//Default pins
#define M_LF_PORT 6
#define M_LB_PORT 5
#define M_RF_PORT 10
#define M_RB_PORT 9

class RasBotArduino{
public:
    RasBotArduino(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port);
    ~RasBotArduino();

    void setPorts(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port);
    void stop();

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
