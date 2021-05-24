//
// Created by Stefan on 3/18/2021.
//

#ifndef LAB1_CAR_H
#define LAB1_CAR_H
#include "Weather.h"

class Car{
public:
    [[nodiscard]] virtual auto fuelCapacity ()            const -> float = 0;
    [[nodiscard]] virtual auto fuelConsumption()          const -> float = 0;
    [[nodiscard]] virtual auto averageSpeed ( Weather )   const -> float = 0;
    [[nodiscard]] virtual auto range()                    const -> float = 0;
    [[nodiscard]] virtual auto getName()                  const -> const char* = 0;

};
#endif //LAB1_CAR_H
