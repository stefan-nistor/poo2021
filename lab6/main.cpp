//
// Created by Stefan on 5/24/2021.
//
#include "Car.h"
#include "Circuit.h"

int main(){
    Circuit c;
    c.setWeather(Weather::SUNNY);
    c.addCar(new Dacia());
    c.addCar(new Toyota());

    c.race();
    c.showFinalRanks();
    c.showWhoDidNotFinish();
}


