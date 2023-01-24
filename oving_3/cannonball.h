
#pragma once

// oppgave 1
// --------------------------------

// 1 a)
double acclY();

// 1 b)
double velY(double initVelocityY, double time);

// 1 c)
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

// 1 d)
void printTime(double seconds);

// 1 e)
double flightTime(double initVelocityY);

// --------------------------------

// oppgave 4
// --------------------------------

// 4 a)

// get input, angle
double getUserInputTheta();

// get input, absolute velocity
double getUserInputAbsVelocity();

// degrees to radians
double degToRad(double deg);

// returns velocity x
double getVelocityX(double theta, double absVelocity);
// returns velocity y
double getVelocityY(double theta, double absVelocity);

// decompose velocity, returns vecotr<double> = {x,y}
vector<double> getVelocityVector(double theta, double absVelocity);

// 4 b)
// returns horizontal distance before hitting ground (distance x direction)
double getDistanceTraveled(double velocityX, double velocityY);

// 4 c)
// retunrs deviation from where to ball lands and where target is
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

// --------------------------------


// oppgave 5
// --------------------------------

// 5 d)
void playTargetPractice();

// --------------------------------