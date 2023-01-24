
#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"


// oppgave 3
// --------------------------------

// 3 b)
void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    
    double comapredAbs = abs(compareOperand - toOperand);
    
    bool holds = comapredAbs <= maxError;
    
    cout << name;

    if (holds){
        cout << " is valid" << endl;
    }
    else{
        cout << " is not valid, expected maxError: " << maxError << " your error: " << comapredAbs << endl; 
    }
}



// --------------------------------



// bool checkIfDistanceToTargetIsCorrect() {
//     double error = targetPractice(100,0,0);
//         if(error == 0) return true;
// }



int main(){

    // oppgave 3 c)
    // --------------------------
    double maxError = 0.001;

    // test acclY
    testDeviation(acclY(), -9.81, maxError, "acclY()");

    // test velY
    testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25, 2.5)");

    // test posX
    testDeviation(posX(0, 50.0, 2.5), 125.0, maxError, "posX(0, 50.0, 2.5");

    // test posY
    testDeviation(posY(0, 25.0, 2.5), 31.84, maxError, "posY(0, 25.0, 2.5)");

    // --------------------------



    // test oppgave 4
    // --------------------------
    double distanceToTarget = 25;
    double rad = degToRad(getUserInputTheta());
    double absVel = getUserInputAbsVelocity();

    vector<double> vel = getVelocityVector(rad, absVel);

    cout << endl;
    cout << "start velocity(x,y): " << vel.at(0) << ", " << vel.at(1) << endl;
    
    cout << "distance to target: " << distanceToTarget << " m" <<endl;
    cout << "distance traveled: " << getDistanceTraveled(vel.at(0), vel.at(1)) << " m"<< endl;

    cout << "--------------- " << endl;
    cout << "missed by: " << targetPractice(distanceToTarget, vel.at(0), vel.at(1)) << " m" << endl;
    // --------------------------

    // test oppgave 5
    // --------------------------
    for (int i = 0; i < 50; i++){
        int number = randomWithLimits(0,200);
    }




    // --------------------------


    return 0;
}