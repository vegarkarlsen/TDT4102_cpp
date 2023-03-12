#include <string>
#include <memory>


#include "car.h"

class Person{
    private:
        std::string name;
        std::string email;
        std::unique_ptr<Car> car;
    
    public:
        Person(std::string n, std::string m, std::unique_ptr<Car> c = nullptr);
        std::string getName() const;
        std::string getEmail() const;
        void setEmail(std::string mail);

        bool hasAvailibleSeat() const;

        friend std::ostream& operator<<(std::ostream &os, const Person &p);

};