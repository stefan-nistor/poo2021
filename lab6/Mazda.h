//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_MAZDA_H
#define LAB1_MAZDA_H
#include "Car.h"

class Mazda : public Car{


    auto fuelCapacity() const  -> float override {
        return 55.0f;
    }

    auto fuelConsumption () const  -> float override {
            return 0.58f;
    }

    auto averageSpeed (Weather weather) const  -> float override {
        switch (weather) {
            case Weather::RAIN:     return 86.5f;
            case Weather::SNOW:     return 62.9f;
            case Weather::SUNNY:    return 134.6f;
        }
        return 0;
    }

    auto range() const -> float override{
        return fuelCapacity() / fuelConsumption();
    }


    auto getName() const -> char* override{
        return "Mazda";
    }
};


#endif //LAB1_MAZDA_H
