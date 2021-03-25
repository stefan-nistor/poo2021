#include  <iostream>
#include "lab6/Circuit.h"

int main()
{
    Circuit c;

    c.setLength(10);
    c.setWeather(Weather::SNOW);

    c.addCar(new Dacia());
    c.addCar(new Toyota());
    c.addCar(new Mercedes());
    c.addCar(new Mazda());
    c.addCar(new Ford());

    c.race();
    c.showFinalRanks();
    c.showWhoDidNotFinish();
    return 0;
}