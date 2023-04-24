
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
#include <memory>

#include "person.h"
#include "LinkedList.h"


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



int main() {

    // std::vector<std::string> strs = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur", "Dolor"};

    // std::set<std::string> set_strs = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur", "Dolor"};


    // task_1a_set(set_strs);
    
    // std::cout << std::endl;
    // replace_set(set_strs, "Dolor", "test");

    // task_1a_set(set_strs);

    // std::list<Person> l;
    // Person pa{"An", "gs"};
    // Person pb{"Bn", "gs"};
    // Person pc{"Cn", "gs"};
    // Person pd{"Dn", "gs"};
    // Person pe{"En", "gs"};

    // insertOrdered(l, pa);
    // insertOrdered(l, pb);
    // insertOrdered(l, pc);
    // insertOrdered(l, pd);
    // insertOrdered(l, pe);

    // for (auto p : l){
    //     std::cout << p << std::endl;
    // }


    // std::cout << (a > b) << std::endl;

    LinkedList::LinkedList l;

    l.insert(l.begin(), "test");
    l.insert(l.end(), "hei");
    l.insert(l.end(), "halla");

    
    std::cout << l.begin()->getValue() << std::endl;
    std::cout <<l.begin()->getNext()->getValue() << std::endl;
    std::cout << l.begin()->getNext()->getNext()->getValue() << std::endl;
    
    std::cout << std::endl;

    // l.remove(l.end());
    // std::cout << l.begin()->getValue() << std::endl;
    // std::cout << l.begin()->getNext()->getValue() << std::endl;
    
    
    return 0;
}