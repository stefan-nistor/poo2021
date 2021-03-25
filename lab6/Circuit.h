//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_CIRCUIT_H
#define LAB1_CIRCUIT_H
#include "Weather.h"
#include "Car.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Toyota.h"

class Circuit {
public:

    float length = 0;
    Weather weather = Weather::SUNNY;
    Car* cars[10] = {};
    unsigned int numberOfCars = 0;

    struct car {
        const char * name;
        float time ;
    } carsOnRace [10];


public:

    inline void setLength(float _length)        noexcept { this->length = _length;}
    inline void setWeather(Weather _weather)    noexcept { this->weather = _weather;}

    inline void addCar(Car* car)                noexcept {cars[Circuit::numberOfCars++] = car;}

    void race()                 noexcept;
    void showFinalRanks()       const noexcept;
    void showWhoDidNotFinish()  const noexcept;
};


#endif //LAB1_CIRCUIT_H
