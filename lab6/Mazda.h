//
// Created by Stefan on 3/24/2021.
//

#ifndef LAB1_MAZDA_H
#define LAB1_MAZDA_H
#include "Car.h"

class Mazda : public Car{


    [[nodiscard]] auto fuelCapacity() const  -> float override {
        return 55.0f;
    }

    [[nodiscard]] auto fuelConsumption () const  -> float override {
            return 0.58f;
    }

    [[nodiscard]] auto averageSpeed (Weather weather) const  -> float override {
        switch (weather) {
            case Weather::RAIN:     return 86.5f;
            case Weather::SNOW:     return 62.9f;
            case Weather::SUNNY:    return 134.6f;
        }
        return 0;
    }

    [[nodiscard]] auto range() const -> float override{
        return fuelCapacity() / fuelConsumption();
    }


    [[nodiscard]] auto getName() const -> const char* override{
        return "Mazda";
    }
};


#endif //LAB1_MAZDA_H
