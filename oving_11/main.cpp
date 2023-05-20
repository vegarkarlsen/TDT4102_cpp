
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
#include <memory>

#include "person.h"
#include "linkedListGen.hpp"
#include "logger.hpp"

#include "std_lib_facilities.h"


void task_1a(std::vector<std::string> &strs){

    // for (auto word = strs.cbegin(); word != strs.cend(); word++ ){
    //     std::cout << *word << std::endl;
    // }
    auto test = strs.begin();
    for (auto it = strs.begin(); it != strs.end(); it++){
        std::cout << *it << std::endl;
    }

}

void task_1a_set(std::set<std::string> &strs){

    // for (auto word = strs.cbegin(); word != strs.cend(); word++ ){
    //     std::cout << *word << std::endl;
    // }
    auto test = strs.begin();
    for (auto it = strs.begin(); it != strs.end(); it++){
        std::cout << *it << std::endl;
    }
}



void task_1b(std::vector<std::string> &strs){

    // for (auto word = --strs.cend(); word != --strs.cbegin(); word--){
    //     std::cout << *word << std::endl;
    // }
    for (std::vector<std::string>::const_reverse_iterator word = strs.crbegin(); word != strs.crend(); word++){
        std::cout << *word << std::endl;
    }
}

void task_1b_set(std::set<std::string> &strs){

    // for (auto word = --strs.cend(); word != --strs.cbegin(); word--){
    //     std::cout << *word << std::endl;
    // }
    for (std::set<std::string>::const_reverse_iterator word = strs.crbegin(); word != strs.crend(); word++){
        std::cout << *word << std::endl;
    }
}


void replace(std::vector<std::string> &strs, std::string old, std::string replacement){

    std::vector<std::string>::iterator it;
    
    while (it != strs.end()){
        it = find(strs.begin(), strs.end(), old);
        if (it != strs.end()){
            strs.erase(it);
            strs.insert(it, replacement);
        }
    }
}

void replace_set(std::set<std::string> &strs, std::string old, std::string replacement){

    std::set<std::string>::iterator it;
    
    while (it != strs.end()){
        it = find(strs.begin(), strs.end(), old);
        if (it != strs.end()){
            strs.erase(it);
            strs.insert(replacement);
        }
    }
}



void testMovePtr(){
    int i = 5;
    int n = 16;

    int *iPtr = &i;

    int *ptr2 = iPtr;


    *iPtr = 6;
    *ptr2 = 10;

    iPtr = &n;
    *ptr2 = 23;
    std::cout << "ptr 1: " <<*iPtr << std::endl;
    std::cout << "ptr 2: " <<*ptr2 << std::endl;
    std::cout << "i: " << i << std::endl;


}

template<typename T>
T maximum(T a, T b){
    T r = a;
    if (b > r){
        r = b;
    }
    return r;
}

template<typename T>
void shuffleVector(std::vector<T>& vec){
    int a;
    int b;
    
    T temp;
    int size = static_cast<int>(vec.size()) - 1;

    int times = randint(100, 1000);
    for (int i = size; i < times; i++){
        // two random numbers
        a = randint(size);
        b = randint(size);
        
        if (a == b){
            continue;
        }
        // swap
        temp = vec.at(a);
        vec.at(a) = vec.at(b);
        vec.at(b) = temp;
 
    }
}



int main() {
    
    LinkedList<std::string> l;
    // std::cout << "head " << l.begin() << " tail " << l.end(); 

    l.insert(l.end(), "1");
    l.insert(l.end(), "2");
    l.insert(l.end(), "3");
    
    // l.remove(l.begin()->getNext()->getNext());

    // std::cout << *l.begin() << std::endl;
    // std::cout << *l.begin()->getNext() << std::endl;
    // std::cout << *l.begin()->getNext()->getNext() << std::endl;

    std::cout << l << std::endl;



    return 0;
}