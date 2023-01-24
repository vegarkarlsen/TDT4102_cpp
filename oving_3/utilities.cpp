
#include "std_lib_facilities.h"
#include "utilities.h"

// oppgave 5 
// --------------------------
// 5 b)
int randomWithLimits(int min, int max){
    std::default_random_engine generator;
    int number = generator();
    std::cout << number;
}



// --------------------------