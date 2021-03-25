//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_MERCEDES_H
#define LAB1_MERCEDES_H
#include "Car.h"

class Mercedes : public Car{
    auto fuelCapacity() const  -> float override {
        return 60.0f;
    }

    auto fuelConsumption () const  -> float override {
        return 0.7f;
    }

    auto averageSpeed (Weather weather) const  -> float override {
        switch (weather) {
            case Weather::RAIN:     return 90.5f;
            case Weather::SNOW:     return 69.4f;
            case Weather::SUNNY:    return 140.6f;
        }
        return 0;
    }

    auto range() const -> float override{
        return fuelCapacity() / fuelConsumption();
    }


    auto getName() const -> char* override{
        return "Mercedes";
    }
};


#endif //LAB1_MERCEDES_H
