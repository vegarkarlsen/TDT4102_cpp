
#include <iostream>
#include "matrix.h"

// #include "dummy.h"

// void fillInFibonacciNumbers(int result, int lenght){
//     int a = 0;
//     int b = 1;
//     int s;
//     std::vector<int> test;
//     for (int i = 2; i < lenght; i++){

//         if (i <= lenght){
//             s = a + b;
//             test.push_back(s);
//             a = b;
//             b = s;
//             std::cout << s << std::endl;
//         }
//     }
    
//     std::cout << "print vector" << std::endl;
//     for (auto t : test){
//         std::cout << t << std::endl;
//     }

// }

void fillInFibonacciNumbers(int *result, int lenght){
    result[0] = 0;
    result[1] = 1;

    for (int i = 2; i < lenght; i++){
        if (i <= lenght){
            result[i] = result[i-1] + result[i-2];
        }
    }
    
}


void printArray(int *arr, int lenght){
    // const int numbersOnLine = 20;
    // int line_index = 0;

    std::cout << "[";
    for (int i = 0; i < lenght; i++){
        
        // newline after numbersOnLine numbers horizontaly
        // if (line_index > numbersOnLine){
        //     std::cout << std::endl;
        //     line_index = 0; 
        // }
        std::cout << arr[i];
        // correcting for last element.
        if (i < lenght- 1){
            std::cout << ", ";
        }
        // line_index++;
    }
    std::cout << "]" << std::endl;
}


void createFibonacci(){
    int size;
    std::cout << "how many fibonacci numbers: ";
    std::cin >> size;

    int *result = new int[size] {};

    fillInFibonacciNumbers(result, size);
    printArray(result, size);

    delete[] result;
    result = nullptr;

}




int main(){
    // fillInFibonacciNumbers(1,10);

    // const int size = 20;
    // int result[size];
    // fillInFibonacciNumbers(result, size);
    // printArray(result, size);

    // createFibonacci();

    // Matrix I {3};
    // Matrix a{3,2};

    // a.set(1,1, 10.0);
    // std::cout << I << std::endl << a << std::endl;

    // std::cout << I.get(1,1);

    // dummyTest();

    return 0;
}