//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor


// oppgave 1 a)
// def is_fibonacci_number(n):
//     a = 0
//     b = 1
//     while a < n:
//         temp = b
//         b += a
//         a = temp

//     return a == n


#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

// oppgave 2 a)
int maxOfTwo(int a,int b){
    if (a > b){
        cout << "a is greater than b" << endl;
        return a;
    }
    else{
        cout << "b is greater than or equal to a" << endl;
        return b;
    }
}


// oppgave 2 c)
int fibonacci(int n){
    int a = 0;
    int b = 1;
    int temp = 0;
    cout << "Fibonacci numbers: " << endl;
    for (int i = 1; i < n + 1; i++){
        cout << i;
        cout << " ";
        cout << b << endl;
        
        temp = b;
        b += a;
        a = temp;
        
    }
    cout << "-----------------------" << endl;
    return b;
}


// oppgave 2 d)
int squareNumberSum(int n){
    int totalSum = 0;

    for (int i = 1; i < n + 1; i++){
        totalSum += i*i;
        cout << i * i << endl;

    }

    cout << totalSum << endl;
    return totalSum;
}



// oppgave 2 e)
int triangleNumbersBelow(int n){
    int acc = 1;
    int num = 2;

    cout << "Triangle numbers below " << n << " : " << endl;
    while (acc < n){
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    return acc;
}


// oppgave 2 f)
bool isPrime(int n){
    for (int i = 2; i < n ; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

// oppgave 2 g)
int naivePrimeNumberSearch(int n){
    
    for (int number = 2; number < n ; number++){
        if (isPrime(number)){
            cout << number << " is a prime" << endl;
        }
        
    }
    return 0;
}

// oppgave 2 h)
int findGreatesDivisor(int n){
    for (int divisor = n - 1; divisor > 0; divisor--){
        if (n % divisor == 0){
            return divisor;
        }
    }
    return 0;
}


// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window

    // oppgave 2 b)
    cout << "oppgave a)" << endl;
    cout << maxOfTwo(5,6) << endl;

    // oppgave 2 c)
    cout << "oppgave c)" << endl;
    cout << fibonacci(5) << endl;

    // opgpave 2 d)
    cout << "oppgave d)" << endl;
    cout << squareNumberSum(5) << endl;

    // oppgave 2 e)
    cout << "oppgave e)" << endl;
    cout << triangleNumbersBelow(10) << endl;

    // oppgave 2 f) and g)
    cout << "oppgave f) and g)" << endl;
    cout << naivePrimeNumberSearch(14) << endl;

    // oppgave 2 h)	
    cout << "oppgave h)" << endl;
    cout << findGreatesDivisor(14) << endl;
    cout << findGreatesDivisor(13) << endl;

    
    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
