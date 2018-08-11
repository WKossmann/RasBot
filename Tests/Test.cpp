#include <wiringPi.h>
#include <softPwm.h>


int main(){
    wiringPiSetup();
    softPwmCreate(0,30,100);

    delay(2000);

    softPwmWrite(0, 100);

    delay(2000);

    softPwmWrite(0,0);

    softPwmCreate(1,30,100);

    delay(2000);

    softPwmWrite(1,100);
    
    delay(2000);

    softPwmWrite(1,0);

    delay(100);

    // pinMode(27,OUTPUT);
    // digitalWrite(27, LOW);
    
    return 0;

}