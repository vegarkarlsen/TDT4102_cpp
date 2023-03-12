#include "person.h"
#include "car.h"
#include <iostream>

int main(){

    Person p{"paal", "paal@n.no", std::make_unique<Car>(3)};
    Person b{"olga", "olga@n.no"}; 
    std::cout << p << std::endl;
    std::cout << b << std::endl;
    // std::cout << p << std::endl;
    return 0;
}