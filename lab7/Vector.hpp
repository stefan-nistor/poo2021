//
// Created by rosawan on 31/03/2021.
//

#ifndef LAB1_VECTOR_HPP
#define LAB1_VECTOR_HPP

template <class T>
class Vector{
public:

    Vector              ();
    Vector              ( int size );
    ~Vector             ();

    void push           ( T );
    void pop            ( T ) const;
    void remove         ( int );
    void insert         ( int );
    void sort           ( void *ptr = nullptr);
    T &get              ();
    void set            ( int );
    int count           ();
    int firstIndexOf    ();

};


#endif //LAB1_VECTOR_HPP
