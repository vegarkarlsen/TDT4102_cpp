#pragma once
#include <string>
#include <ostream>
#include <list>

class Person{
    private:
        std::string name;
        std::string lastname;

    public:
        Person(std::string name, std::string lastname);
        std::string getName() const { return name; };
        std::string getLastName() const { return lastname; };
        friend std::ostream& operator<<(std::ostream &os, Person &p);
     
};

void insertOrdered(std::list<Person> &l, const Person &p);

