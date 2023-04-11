
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

void testString(){
    string grades = randomizeString(8, 'a', 'f');
    cout << grades << endl;

    // there are 6 numbers from a-f
    vector<int> gradeCount(6);
    char charToCount;
    double runningTotal = 0;

    // count characters
    for (int i = 0; i < gradeCount.size(); i++){
        // count
        charToCount = char(i + 'a');

        cout << charToCount << " ";
        gradeCount.at(i) = countChar(grades, charToCount);
        cout << gradeCount.at(i) << endl;

        // iteration wrong way:
        runningTotal += (5 - i)* gradeCount.at(i);
    }

    cout << "average = " << runningTotal/8 << endl;
}

