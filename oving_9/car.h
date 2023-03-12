#pragma once
#include <iostream>


class Car{
    private:
        int freeSeats;

    public:
        bool hasFreeSeats() const;
        void reserveFreeSeat(); 
        Car(int freeSeat);
        
};

