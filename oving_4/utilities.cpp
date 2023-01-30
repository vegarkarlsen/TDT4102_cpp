
#include "utilities.h"


// oppgave 1

int incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++){
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++){
        startValue += increment;
    }
}

// swaps the two int numbers
void swapNumbers(int& value1, int& value2){
    
    // copy of the values
    int value1Copy = value1;

    value1 = value2;
    value2 = value1Copy;
}


// ----------------------------------------------------------------

// oppgave 2

// b
void printStudent(Student student){
    cout << "name: " << student.name << endl;
    cout << "study program: " << student.studyProgram << endl;
    cout << "age: " << student.age << endl;
}

// c
bool isInProgram(Student stud, string studyProgram){
    if (stud.studyProgram == studyProgram) return true;
    else return false;
}
    




// ----------------------------------------------------------------