//
// Created by Stefan on 3/18/2021.
//

#ifndef LAB1_CAR_H
#define LAB1_CAR_H
#include "Weather.h"

class Car{
public:
    virtual auto fuelCapacity ()            const -> float = 0;
    virtual auto fuelConsumption()          const -> float = 0;
    virtual auto averageSpeed ( Weather )   const -> float = 0;
    virtual auto range()                    const -> float = 0;
    virtual auto getName()                  const -> char* = 0;

};
#endif //LAB1_CAR_H
