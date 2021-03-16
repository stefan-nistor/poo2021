//
// Created by Stefan on 3/10/2021.
//

#include <iostream>
#include <cstdarg>
#include <cstring>
#include "Sort.h"

void Sort::pushFront(int value) {

    Node *p = new Node;
    p->value = value;
    p->next = this->front;
    this->front = p;
    this->size ++;

}

void Sort::pushBack(int value) {

    if (isEmpty()){
        pushFront(value);
        return;
    }

    Node *p = this->front;

    while(p->next != nullptr){
        p = p->next;
    }

    p->next = new Node;
    p->next->value = value;
    p->next->next = nullptr;
    this->size++;
}

void Sort::push(int value,  int pos) {

    if(isEmpty() || pos == 0) {
        pushFront(value);
        return;
    }

    Node * p = this->front;
    int i = 1;

    while (p->next != nullptr){
        if (i == pos){

            Node * q = new Node;
            q->next = p->next;
            p->next = q;
            q->value = value;
            this->size++;
            return;
        }
        i++;
        p = p->next;
    }
    pushBack(value);
}

Sort::Sort (int *vector, int count) {
    for(int i = 0; i < count; i++)
        pushBack(vector[i]);
}

Sort::Sort(int count, int min, int max){

    srand (time (nullptr));

    while (count--){
        int value = rand() % max + min;
        pushBack(value);
    }
}

Sort::Sort(std::initializer_list<int>  list) {
    for (auto &i : list)
        pushBack(i);
}

Sort::Sort (int count, ...){

    va_list elements;
    va_start ( elements, count);

    for(int i = 0; i < count; i++)
        pushBack(va_arg(elements, int));

    va_end(elements);

}

Sort::Sort(char const * str){

    char * tmp = new char [strlen(str) + 1];
    strcpy(tmp,str);

    char * token = strtok(tmp, ",");

    while (token != nullptr){

        int value = atoi(token);
        pushBack(value);
        token = strtok(nullptr, ",");
    }
    delete [] tmp;
}


void Sort::print() const {

    if (isEmpty()){
        std::cout << "List is empty\n";
        return;
    }

    Node * p = this-> front;

    while (p != nullptr){
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << '\n';
}

void Sort::insertSort(bool ascendent) {
    for(int i = 1, j; i < getElementsCount(); i++){
        int key = getElementFromIndex(i);
        j = i - 1;
        while (j >= 0 && (ascendent? getElementFromIndex(j) > key : getElementFromIndex(j) < key)){
            get(j + 1) = get(j);
            j--;
        }
        get(j + 1) = key;
    }
}

void Sort::quickSort(bool ascendent) {
    warpQuickSort(0, getElementsCount() - 1, ascendent);
}

void Sort::bubbleSort(bool ascendent) {
    if(isEmpty()) return;

    for(int i = 0; i < getElementsCount() - 1; i++){
        for(int j = 0; j < getElementsCount() - i - 1; j++){
            if(ascendent ? getElementFromIndex(j) > getElementFromIndex(j + 1) :
                            getElementFromIndex(j) <  getElementFromIndex(j + 1) )
                    swap(j + 0 ,j + 1);
        }
    }
}

int Sort::getElementsCount() const {
    return this->size;
}

int Sort::getElementFromIndex(int index) const {

    Node * p = this->front;
    int pos = 0;
    while (!isEmpty()){
        if( pos == index)
            return p->value;
        pos++;
        p = p->next;
    }
    return 0;
}

void Sort::swap(int a_index, int b_index) {

    int temp = get(a_index);
    get(a_index) = get(b_index);
    get(b_index) = temp;

}

int &Sort::get(int index) {

    if(index < 0 || index > this->size)
        throw std::runtime_error("List index out of bounds");

    Node * p = this->front;
    int pos = 0;
    while (!isEmpty()){
        if( pos == index)
            return p->value;
        pos++;
        p = p->next;
    }
    throw std::runtime_error ("List index out of bounds");
}

int Sort::partition(int low, int high, bool ascendant) {
    int pivot = get(high);
    int j = low - 1;

    for(int i = low; i < high; i++) {
        if (ascendant ? get(i) <= pivot : get(i) >= pivot){
            j++;
            swap(i, j);
        }
    }
    swap(j+1, high);
    return j + 1;
}

void Sort::warpQuickSort(int low, int high, bool ascendant) {
    if(low < high){
        int partition_index = this->partition(low, high, ascendant);
        warpQuickSort(low, partition_index - 1, ascendant);
        warpQuickSort(partition_index + 1, high, ascendant);
    }
}