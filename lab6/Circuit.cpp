//
// Created by Stefan on 3/24/2021.
//

#include "Circuit.h"
#include <iostream>

void sort(float * arr, unsigned int len){
    for(int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - i - 1; j++)
            if(arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);

}

void print(float *arr, unsigned int len){
    for(int i = 0; i < len; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void Circuit::showWhoDidNotFinish() const noexcept {
    for (int i = 0; i < numberOfCars; i++) {
        if (cars[i]->range() < length)
            std::cout << cars[i]->getName() << ' ';
        std::cout << '\n';
    }
}

void Circuit::showFinalRanks() const noexcept {
    for(int i = 0; i < numberOfCars; i++)
    {
        std::cout << carsOnRace[i].name << ": "<<carsOnRace[i].time << '\n';
    }
}

void Circuit::race()  noexcept {
    for(int i = 0; i < numberOfCars; i++){
        carsOnRace[i].time = length / cars[i]->averageSpeed(weather);
        carsOnRace[i].name = cars[i]->getName();
    }
    /// sort cars based on their time
    for(int i = 0; i < numberOfCars - 1; i++)
        for(int j = 0; j < numberOfCars - i - 1; j++)
            if(carsOnRace[j].time > carsOnRace[j + 1].time)
            {
                car temp = carsOnRace[j];
                carsOnRace[j] = carsOnRace[j+1];
                carsOnRace[j+1] = temp;
            }
}


