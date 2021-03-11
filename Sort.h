//
// Created by Stefan on 3/10/2021.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H
#include <initializer_list>
#include <stdlib.h>
#include <time.h>

class Sort
{
private:

    struct Node {
        Node * next;
        int value;
    };

    Node * front {nullptr};

    inline bool isEmpty () const { return this->front == nullptr; }

    int size = 0;

    void pushFront (int value);
    void pushBack (int value);
    void push (int value, int pos);

    void swap(int a_index, int b_index);

    int &get (int index);

    int partition (int low, int high, bool ascendant);
    void warpQuickSort(int low, int high, bool ascendant);

public:

    Sort (int count, int min, int max);
    Sort (std::initializer_list<int>);
    Sort (int* vector, int count);
    Sort (int count,  ... );
    Sort (char const * str);

    void insertSort (bool ascendent=false);
    void quickSort  (bool ascendent=false);
    void bubbleSort (bool ascendent=false);

    void print () const;

    int  getElementsCount () const;
    int  getElementFromIndex (int index) const;
};


#endif //LAB1_SORT_H
