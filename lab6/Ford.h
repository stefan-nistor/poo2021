//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_FORD_H
#define LAB1_FORD_H
#include "Car.h"

class Ford : public Car{

    auto fuelCapacity() const -> float override {
        return 70.0f;
    }

    auto fuelConsumption () const -> float override {
        return 1.2f;
    }

    auto averageSpeed (Weather weather) const -> float override {
        switch (weather) {
            case Weather::RAIN:     return 112.5f;
            case Weather::SNOW:     return 85.9f;
            case Weather::SUNNY:    return 164.6f;
        }
        return 0;
    }

    auto range() const -> float override{
        return fuelCapacity() / fuelConsumption();
    }

    auto getName() const -> char* override{
        return "Ford";
    }

};


#endif //LAB1_FORD_H
