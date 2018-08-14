#include "RasBotArduino.h"
#include "Arduino.h"

RasBotArduino::RasBotArduino(int _mLF_port = M_LF_PORT, int _mLB_port = M_LB_PORT, int _mRF_port = M_RF_PORT, int _mRB_port = M_RB_PORT){
    m_LF = _mLF_port;
    m_LB = _mLB_port;
    m_RF = _mRF_port;
    m_RB = _mRB_port;

    pinMode(m_LF, OUTPUT);
    pinMode(m_LB, OUTPUT);
    pinMode(m_RF, OUTPUT);
    pinMode(m_RB, OUTPUT);

//    #ifdef PRINT_DEBUG
//    Serial.println("Config GPIO ... Done");
//    #endif
}
RasBotArduino::~RasBotArduino(){
    stop();
}
void RasBotArduino::setPorts(int _mLF_port, int _mLB_port, int _mRF_port, int _mRB_port){
    m_LF = _mLF_port;
    m_LB = _mLB_port;
    m_RF = _mRF_port;
    m_RB = _mRB_port;

    pinMode(m_LF, OUTPUT);
    pinMode(m_LB, OUTPUT);
    pinMode(m_RF, OUTPUT);
    pinMode(m_RB, OUTPUT);

//    #ifdef PRINT_DEBUG
//    Serial.println("Config GPIO ... Done");
//    #endif
}
void RasBotArduino::stop(){
    digitalWrite(m_LF, LOW);
    digitalWrite(m_LB, LOW);
    digitalWrite(m_RF, LOW);
    digitalWrite(m_RB, LOW);
}
void RasBotArduino::moveF(int relative_velocity){
//    #ifdef PRINT_DEBUG
//    Serial.print("Forward  -> ");
//    #endif

    motorL(1, relative_velocity);
    motorR(1, relative_velocity);

//    #ifdef PRINT_DEBUG
//    Serial.println(" ");
//    #endif
}
void RasBotArduino::moveB(int relative_velocity){
//    #ifdef PRINT_DEBUG
//    Serial.print("Backward  -> ");
//    #endif

    motorL(0, relative_velocity);
    motorR(0, relative_velocity);

//    #ifdef PRINT_DEBUG
//    Serial.println(" ");
//    #endif
}
void RasBotArduino::turnL(int relative_velocity){
//    #ifdef PRINT_DEBUG
//    Serial.print("Right  -> ");
//    #endif

    motorL(0, relative_velocity);
    motorR(1, relative_velocity);

//    #ifdef PRINT_DEBUG
//    Serial.println(" ");
//    #endif
}
void RasBotArduino::turnR(int relative_velocity){
//    #ifdef PRINT_DEBUG
//    Serial.print("Left  -> ");
//    #endif

    motorL(1, relative_velocity);
    motorR(0, relative_velocity);

//    #ifdef PRINT_DEBUG
//    Serial.println(" ");
//    #endif
}
void RasBotArduino::motorL(int direction, int relative_velocity){
    if(direction){
        analogWrite(m_LB,0);
        analogWrite(m_LF, relative_velocity);
        
//        #ifdef PRINT_DEBUG
//        Serial.print(" \t L: -");
//        Serial.print(relative_velocity);
//        #endif
    }else{
        analogWrite(m_LF,0);
        analogWrite(m_LB, relative_velocity);
        
//        #ifdef PRINT_DEBUG
//        Serial.print(" \t L: -");
//        Serial.print(relative_velocity);
//        #endif
    }
}
void RasBotArduino::motorR(int direction, int relative_velocity){
    if(direction){
        analogWrite(m_RB,0);
        analogWrite(m_RF, relative_velocity);

//        #ifdef PRINT_DEBUG
//        Serial.print(" \t L: -");
//        Serial.print(relative_velocity);
//        #endif
    }else{
        analogWrite(m_RF,0);
        analogWrite(m_RB, relative_velocity);

//        #ifdef PRINT_DEBUG
//        Serial.print(" \t L: -");
//        Serial.print(relative_velocity);
//        #endif
    }
}
