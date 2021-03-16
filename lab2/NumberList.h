//
// Created by Stefan on 2/25/2021.
//

#ifndef LAB1_NUMBERLIST_H
#define LAB1_NUMBERLIST_H


class NumberList {
private:
    int numbers[10];
    int count;
public:
    void Init();
    bool Add(int x);

    void Sort();
    void Print();
};


#endif //LAB1_NUMBERLIST_H
