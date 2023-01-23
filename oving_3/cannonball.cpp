
#include "std_lib_facilities.h"
#include "cannonball.h"

// oppgave 2
// --------------------------------

// 1 a)
double acclY(){
    return -9.81; // ms^-2    
}

// 1 b)
double velY(double initVelocityY, double time){
    return initVelocityY + (acclY() * time);
}

// 1 c)
double posX(double initPosition, double initVelocity, double time){
    return initPosition + (initVelocity * time);
}
double posY(double initPosition, double initVelocity, double time){
    return initPosition + (initVelocity * time) + (acclY() * pow(time,2))/2;
}

// 1 d)
void printTime(double seconds){
    int hours = int(seconds) / 3600;
    int minutes = (int(seconds) % 3600) / 60;
    int roundedSeconds = (int(seconds) % 3600) % 60;
    // add the rest of doubble to secounds
    double realSeconds = roundedSeconds + (seconds - int(seconds)); 

    cout << "Hours: "  << hours << endl;
    cout << "Minutes: "<< minutes << endl;
    cout << "Seconds: " << realSeconds << endl;
}

// 1 e)
double flightTime(double initVelocityY){
    return (-2 * initVelocityY)/(acclY());
}

// --------------------------------