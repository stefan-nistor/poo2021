//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_TOYOTA_H
#define LAB1_TOYOTA_H
#include "Car.h"

class Toyota : public Car{
    auto fuelCapacity () const -> float override {
        return 43.0f;
    }

    auto fuelConsumption () const -> float override {
        return 0.62f;
    }

    auto averageSpeed (Weather weather) const -> float override {
        switch (weather) {
            case Weather::RAIN:     return 89.5f;
            case Weather::SNOW:     return 61.6f;
            case Weather::SUNNY:    return 138.25f;
        }
        return 0;
    }

    auto range() const -> float override{
        return fuelCapacity() / fuelConsumption();
    }


    auto getName() const -> char* override{
        return "Toyota";
    }
};


#endif //LAB1_TOYOTA_H
