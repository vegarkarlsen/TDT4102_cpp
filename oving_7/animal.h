#pragma once
#include "std_lib_facilities.h"


class Animal{
    protected:
        string name;
        int age;
        
    public:
        Animal(string nam, int ag);
        virtual ~Animal(){};
        virtual string toString() = 0;

};


class Cat : public Animal{
    public:
        Cat(string nam, int ag);

        string toString();

};

class Dog : public Animal{
    public:
        Dog(string nam, int ag);
        string toString();
};

