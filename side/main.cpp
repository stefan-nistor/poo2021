//
// Created by Stefan on 4/22/2021.
//

#include <iostream>

class Car {
public:
    const char * color;
    unsigned int year;
    unsigned int speed;
public:
    Car() : color("default"), year(0), speed(0) {};
    Car(const char * color, unsigned int year, unsigned  int speed) : color(color), year(year), speed(speed) {};

};

class Garaj{
    Car c[100] = {};
    unsigned int nrOfCars;
public:

    class MyIterator{
        Car* c;
        unsigned int index;
    public:
        MyIterator(Car* c, unsigned int index) : c(c), index(index) {}

        MyIterator& operator++()                {index++; return *this;}
        bool operator!=(MyIterator& it) const   {return this->index != it.index;}
        inline Car operator*() const noexcept   {return c[index];}

    };

    Garaj() { nrOfCars = 0;}

    MyIterator begin()    {return MyIterator(c, 0);}
    MyIterator end()      {return MyIterator(c, nrOfCars);}

    inline auto addCar(Car newCar) {c[nrOfCars++] = newCar;}

};

int main(){
    Garaj g;
    g.addCar(Car("red", 2000,100));
    g.addCar(Car("blue", 2014,120));
    g.addCar(Car("white", 1902,103));

    for(auto c : g){
        printf("%s %d %d\n", c.color, c.speed, c.year);
    }

    return 0;
}