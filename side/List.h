//
// Created by Stefan on 3/14/2021.
//

#ifndef LAB1_LIST_H
#define LAB1_LIST_H
#include <initializer_list>
#include <cstring>
#include <stdexcept>
#include <iostream>

template <class T = int>
class List {
private:
    struct Node {
        T value;
        Node* pNext;
    };

    Node *pFront {nullptr};
    unsigned int size = 0;

public:
    inline List() {pFront = nullptr;}
    List(std::initializer_list<T>);
    List (T elements, int count);

    inline bool empty() const { return pFront == nullptr; }

    void pushFront(T value);
    void pushBack(T value);
    void push(T value, int index);

    T popFront();
    T popBack();
    T pop (int index);

    T &get (int index);
    void print() const ;
};

template<class T>
List<T>::List(std::initializer_list<T> list) {
    for(auto &value : list)
        pushBack(value);
}

template<class T>
List<T>::List(T elements, int count) {
    for(int i = 0; i < count; i++)
        pushBack(elements[i]);
}

template<class T>
void List<T>::pushFront(T value) {
    Node *p = new Node;
    p->value = value;
    p->pNext = pFront;
    pFront = p;
    size++;
}

template<class T>
void List<T>::pushBack(T value) {
    if(empty()){
        pushBack(value);
        return;
    }

    Node *p = pFront;
    while(p->pNext){
        p = p->pNext;
    }

    p->pNext = new Node;
    p->pNext->value = value;
    p->pNext->pNext = nullptr;
    size++;
}

template<class T>
void List<T>::push(T value, int index) {

    if(empty() || index == 0){
        pushFront(value);
        return;
    }

    Node *p = pFront; int i = 1;
    while(p->pNext){
        if(i == index){
            Node * q = new Node;
            q->pNext = p->pNext;
            p->pNext = q;
            q->value = value;
            size++;
            return;
        }
        i++;
        p = p->pNext;
    }

    pushBack(value);
}

template<class T>
T &List<T>::get(int index) {

    if(index < 0)
        throw std::runtime_error("List index out of bounds");

    Node * p = pFront;
    int i = 0;
    while(!empty()){
        if(i == index)
            return p->value;
        i++;
        p = p->pNext;
    }

    throw std::runtime_error ("List index out of bounds");
}

template<class T>
void List<T>::print() const {

    if(empty()){
        std::cout << "List is empty\n";
        return;
    }

    std::cout << "\n[ " << get(0) << ", ";
    for(int i = 1; i < size - 1; i++)
        std::cout << get(i) << ", ";
    std::cout << get(size) << " ]";

}


//template<>
//List<std::string>::List(std::string elements, int count) {
//   // char * temp = new char [strlen(elements) + 1];
//   // strcpy(temp, elements);
//
//   std::string temp {nullptr};
//    char * token = strtok(temp, ",");
//
//    while(token){
//        pushBack(token);
//        token = strtok (nullptr, ",");
//    }
//
//    delete [] temp;
//}



#endif //LAB1_LIST_H
