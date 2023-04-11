#include "person.h"

Person::Person(std::string n, std::string m, std::unique_ptr<Car> c) : 
name{n}, 
email{m}, 
car{std::move(c)} 
{} 

std::string Person::getName() const { 
    return this->name; 
}

std::string Person::getEmail() const {
    return this->email;
}

void Person::setEmail(std::string mail){
    this->email = mail;
}

bool Person::hasAvailibleSeat() const {
    return car.get() != nullptr && car->hasFreeSeats();
}

std::ostream& operator<<(std::ostream &os, const Person &p){
    os << "name: " << p.name << std::endl;
    os << "email: " << p.email << std::endl;
    os << "has car? " << (p.car.get() != nullptr) << std::endl;
    return os;
}






