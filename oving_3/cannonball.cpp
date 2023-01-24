
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

// oppgave 4
// --------------------------------

// 4 a)

// get input, angle degree
double getUserInputTheta(){
    double angle;
    cout << "angle [degree]: ";
    cin >> angle;

    return angle;
}

// get input, absolute velocity
double getUserInputAbsVelocity(){
    double absVel;
    cout << "absolute velcoity: ";
    cin >> absVel;

    return absVel;
}

// degrees to radians
double degToRad(double deg){
    return deg * (M_PI/180);
}

// returns velocity x
double getVelocityX(double theta, double absVelocity){
    return absVelocity * cos(theta);
}
// returns velocity y
double getVelocityY(double theta, double absVelocity){
    return absVelocity * sin(theta);
}

// decompose velocity, returns vecotr<double> = {x,y}
vector<double> getVelocityVector(double theta, double absVelocity){
    return {
        getVelocityX(theta, absVelocity),
        getVelocityY(theta, absVelocity)
    };
}

// 4 b)
// returns horizontal distance before hitting ground (distance x direction)
double getDistanceTraveled(double velocityX, double velocityY){
    // s = vt 
    return velocityX * flightTime(velocityY);

}

// 4 c)
// retunrs deviation from where to ball lands and where target is
double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return abs(distanceToTarget - getDistanceTraveled(velocityX, velocityY));

}

// 4 e)
// fuksjonen retunerer ikke noe dersom if - setningen ikke er sann, dette vil derfor gi 
// feilmelding

// --------------------------------