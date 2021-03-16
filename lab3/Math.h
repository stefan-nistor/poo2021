//
// Created by rosawan on 04/03/2021.
//

#ifndef POO2021_MATH_H
#define POO2021_MATH_H

class Math {

public:
    static int Add(int,int);
    static int Add(int,int,int);
    static double Add(double,double);
    static double Add(double,double,double);
    static int Mul(int,int);
    static int Mul(int,int,int);
    static double Mul(double,double);
    static double Mul(double,double,double);
    static int Add(int count,...); // sums up a list of integers
    static char* Add(const char *, const char *);
};


#endif //POO2021_MATH_H
