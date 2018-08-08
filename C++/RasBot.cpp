#include "RasBot.h"

RasBot::RasBot(){}
RasBot::RasBot(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port){
    m_LF = _mLF_port;
    m_LB = _mLB_port;
    m_RF = _mRF_port;
    m_RB = _mRB_port;

    #ifndef CHECK_CODE_OUTSIDE_RASP
    if(wiringPiSetup() == -1){
        #ifdef PRINT_DEBUG
        std::cout << "Erro config GPIO" << std::endl;
        #endif
        exit(1);
    }
    pinMode(m_LF, PWM_OUTPUT);
    pinMode(m_LB, PWM_OUTPUT);
    pinMode(m_RF, PWM_OUTPUT);
    pinMode(m_RB, PWM_OUTPUT);
    #endif
}
RasBot::~RasBot(){
}

bool RasBot::setPorts(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port){
    m_LF = _mLF_port;
    m_LB = _mLB_port;
    m_RF = _mRF_port;
    m_RB = _mRB_port;

    #ifndef CHECK_CODE_OUTSIDE_RASP
    if(wiringPiSetup() == -1){
        #ifdef PRINT_DEBUG
        std::cout << "Config GPIO ... Error" << std::endl;
        #endif
        return false;
    }
    pinMode(m_LF, PWM_OUTPUT);
    pinMode(m_LB, PWM_OUTPUT);
    pinMode(m_RF, PWM_OUTPUT);
    pinMode(m_RB, PWM_OUTPUT);
    #endif

    #ifdef PRINT_DEBUG
    std::cout << "Config GPIO ... Done" << std::endl;
    #endif

    return true;
}

void RasBot::moveF(int relative_velocity){
    #ifdef PRINT_DEBUG
    std::cout << "Forward  -> ";
    #endif

    motorL(1, relative_velocity);
    motorR(1, relative_velocity);

    #ifdef PRINT_DEBUG
    std::cout << std::endl;
    #endif
}
void RasBot::moveB(int relative_velocity){
    #ifdef PRINT_DEBUG
    std::cout << "Backward -> ";
    #endif

    motorL(0, relative_velocity);
    motorR(0, relative_velocity);

    #ifdef PRINT_DEBUG
    std::cout << std::endl;
    #endif
}
void RasBot::turnL(int relative_velocity){
    #ifdef PRINT_DEBUG
    std::cout << "Left     -> ";
    #endif

    motorL(0, relative_velocity/2);
    motorR(1, relative_velocity/2);
    
    #ifdef PRINT_DEBUG
    std::cout << std::endl;
    #endif
}
void RasBot::turnR(int relative_velocity){
    #ifdef PRINT_DEBUG
    std::cout << "Right    -> ";
    #endif

    motorL(1, relative_velocity/2);
    motorR(0, relative_velocity/2);
    
    #ifdef PRINT_DEBUG
    std::cout << std::endl;
    #endif
}
void RasBot::motorL(int direction, int relative_velocity){
    if(direction){
        #ifndef CHECK_CODE_OUTSIDE_RASP
        digitalWrite(m_LB, LOW);
        pwmWrite(m_LF,relative_velocity);
        #endif
        #ifdef PRINT_DEBUG
        std::cout << " \t L:  " << relative_velocity;
        #endif
    }else{
        #ifndef CHECK_CODE_OUTSIDE_RASP
        digitalWrite(m_LF, LOW);
        pwmWrite(m_LB,relative_velocity);
        #endif
        #ifdef PRINT_DEBUG
        std::cout << " \t L: -" << relative_velocity;
        #endif
    }
}
void RasBot::motorR(int direction, int relative_velocity){
    if(direction){
        #ifndef CHECK_CODE_OUTSIDE_RASP
        digitalWrite(m_RB, LOW);
        pwmWrite(m_RF,relative_velocity);
        #endif
        #ifdef PRINT_DEBUG
        std::cout << " \t R:  " << relative_velocity;
        #endif
    }else{
        #ifndef CHECK_CODE_OUTSIDE_RASP
        digitalWrite(m_RF, LOW);
        pwmWrite(m_RB,relative_velocity);
        #endif
        #ifdef PRINT_DEBUG
        std::cout << " \t R: -" << relative_velocity;
        #endif
    }
}