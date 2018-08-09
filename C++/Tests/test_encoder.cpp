#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>

using namespace std;

int main(){
    wiringPiSetup();
    //softPwmCreate(0,30,100);
    pinMode(8,INPUT);
    
    bool trig = false;
    long int cont = 0;
    while(1){
    	if(digitalRead(8)){
    	    if(!trig){
		delay(10);
    	        trig = true;
    	        cont++;
    	        cout << cont << endl;
	    }
    	}else{
    	    if(trig)
		trig = false;
    	}
    }
    return 0;
}