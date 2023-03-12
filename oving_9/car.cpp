#include "car.h"

Car::Car(int freeSeat) : freeSeats{freeSeat}{

}

bool Car::hasFreeSeats() const {
    return freeSeats > 0;
}

void Car::reserveFreeSeat(){
    freeSeats--;
}

