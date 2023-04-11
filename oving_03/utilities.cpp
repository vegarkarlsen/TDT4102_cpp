
#include "std_lib_facilities.h"
#include "utilities.h"

// oppgave 5 
// --------------------------
// 5 b) and c
int randomWithLimits(int min, int max){

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> dist(min, max);

    int number = dist(generator);
    //cout << number << endl;

    return number;
}

// --------------------------