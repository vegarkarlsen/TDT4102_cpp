#include "person.h"


Person::Person(std::string name, std::string lastname) : 
name{name}, lastname{lastname} 
{ }

std::ostream& operator<<(std::ostream &os, Person &p){
    os << "name: " << p.name << "\n"
        << "lastname: " << p.lastname << std::endl;
    return os;
}


void insertOrdered(std::list<Person> &l, const Person &p){
    bool inserted = false;

    if (!l.empty()){
    
        for (auto it = l.begin(); it != l.end(); it++){
            // a < b
            if (it->getName() > p.getName()){
                l.insert(it, p);
                return;
            }
        }
        // no element got inserted, means p should be last element in list
        l.push_back(p);
    }
    // list empty, insert at back.
    else {
        l.push_back(p);
    }
    
}