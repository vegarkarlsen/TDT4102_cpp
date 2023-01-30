
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


// oppgave 3

// b
string randomizeString(int numCharacters, char minCharacter, char maxCharacter){

    // int firstCharInt = (int)maxCharacter;
    int firstCharInt = (int)minCharacter;
    int lastCharInt = (int)maxCharacter;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> dist(firstCharInt, lastCharInt);

    // debug
    // cout << "chars between " << firstCharInt << minCharacter << " and " << lastCharInt << maxCharacter << endl;

    string str = "";
    char currentChar;
    for (int i = 0; i < numCharacters; i++){
        currentChar = char(dist(generator));
        // cout << "random num: " << (int)currentChar << endl; // debuging
        str += currentChar;
    }
    return str;
}

// d
// input string

string readInputToString(char minChar, char maxChar, int n){
    
    string input;
    char currentChar;
    bool approved = 0;
    int checkSum = 0;

    cout << "input a string with only characters between " << minChar 
        << " and " << maxChar 
        << "and minium lenght of " << n << endl;

    cout << "String: ";

    while (!approved){
        cin >> input;

        int inputLength = input.length();
        
        // check the string for all the criteria:
        checkSum = 0;
        for (int i = 0; i < inputLength; i++){
            currentChar = tolower(input[i]);
            
            // debug
            //cout << "checking: " << currentChar << endl;

            // char in intervall and long enough
            if (currentChar >= minChar && currentChar <= maxChar && inputLength == n){
                checkSum += 1;
                //cout << "iteration: " << i << " has checksm " << checkSum << endl;
            }
        }
        
        if (checkSum == inputLength){
            approved = 1;
            break;
        
        }else {
            cout << "input did not pass please try again." << endl;
            cout << "string: ";
        }
        

    }
    // returns only the n characters
    return input.substr(0, n);
        

    
}


// could also iterate trough an sum up
int countChar(string str, char c){
    return count(str.begin(), str.end(), c);
}


