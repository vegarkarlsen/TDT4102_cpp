
#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"


// oppgave 1

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0
            << " increment: " << increment
            << " iterations: " << iterations
            << " result: " << result << endl;
}


// with referanse
void testCallByReferance() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;

    // need to printout before changing
    std::cout << "v0: " << v0;
    incrementByValueNumTimesRef(v0, increment, iterations);
    std::cout  
            << " increment: " << increment
            << " iterations: " << iterations
            << " result: " << v0 << endl;
}


// test swap
void testSwapNumbers(){
    int number1 = 20;
    int number2 = 50;
    // before swap
    cout << "before swap: " << endl;
    cout << "numeber1: " << number1 << endl;
    cout << "numeber2: " << number2 << endl;

    swapNumbers(number1, number2);

    // after swap
    cout << "\nafter swap: " << endl;
    cout << "numeber1: " << number1 << endl;
    cout << "numeber2: " << number2 << endl;   
}

// ----------------------------------------------------------------

// oppgave 2
void testStudent(){
    Student stud = {"Nils", "Automation", 25};
    printStudent(stud);

    bool check = isInProgram(stud, "Automation");
    cout << "isInProgram(stud, 'Automation'): " << check << endl;

    check = isInProgram(stud, "Robotics");
    cout << "isInProgram(stud, 'Robotics'): " << check << endl;
    

}