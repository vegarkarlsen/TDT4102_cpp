
#pragma once
#include "std_lib_facilities.h"



// oppgave 1

int incrementByValueNumTimes(int startValue, int increment, int numTimes);


void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

// swaps the two int numbers
void swapNumbers(int& value1, int& value2);


// oppgave 2
// a
struct Student{
    string name;
    string studyProgram;
    int age;
};

// b
void printStudent(Student student);

// c
bool isInProgram(Student stud, string studyProgram);

