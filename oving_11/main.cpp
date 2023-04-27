
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
#include <memory>

#include "person.h"
#include "LinkedList.h"
#include "logger.hpp"


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


int main() {
    
    LinkedList::LinkedList l;

    // l.insert(l.end(), "1");
    // l.insert(l.end(), "2");

    int list[] = {1,2,3};
    int *head = list;
    int const *tail = head;

    int newList[] = {4,5,6};
    head = newList;

    INFO("head: " << head[0] << " tail: " << tail[0]);

    // std::cout << l << std::endl;
    return 0;
}