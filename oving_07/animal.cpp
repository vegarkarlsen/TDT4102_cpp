#include "std_lib_facilities.h"
#include "animal.h"


Animal::Animal(string nam, int ag) : name{nam}, age{ag} {
}

// string Animal::toString(){
//     return "Animal: " + this->name + ", " + to_string(this->age);
    
// }

Cat::Cat(string nam, int ag) : Animal{nam, ag}{}


string Cat::toString(){
    return "Cat: " + this->name + ", " + to_string(this->age);
}


Dog::Dog(string nam, int ag) : Animal{nam, ag}{}

string Dog::toString(){
    return "Dog: " + this->name + ", " + to_string(this->age);
}

