//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_DACIA_H
#define LAB1_DACIA_H

#include "Car.h"

class Dacia : public Car{
public:

    auto fuelCapacity () const  -> float override {
        return 50.0f;
    }

    auto fuelConsumption () const  -> float override {
        return 0.7f;
    }

    auto averageSpeed (Weather weather) const  -> float override {
        switch (weather) {
            case Weather::RAIN:     return 73.5f;
            case Weather::SNOW:     return 50.9f;
            case Weather::SUNNY:     return 103.6f;
        }
        return 0;
    }

    auto range() const -> float override{
        return fuelCapacity() / fuelConsumption();
    }

    auto getName() const -> char* override{
        return "Dacia";
    }

};


#endif //LAB1_DACIA_H
