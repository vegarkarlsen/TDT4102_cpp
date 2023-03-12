#include "dummy.h"


Dummy::Dummy(const Dummy& newObject) : num{nullptr}{
    this->num = new int {};
    *this->num = *newObject.num;
}

Dummy &Dummy::operator=(Dummy tempCopy){
    std::swap(this->num, tempCopy.num);
    return *this;
}


void dummyTest() {

    Dummy a;

    *a.num = 4;

    Dummy b{a};
    Dummy c;

    c = a;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';

    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';
}