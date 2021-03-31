//
// Created by rosawan on 31/03/2021.
//

#ifndef LAB1_VECTOR_HPP
#define LAB1_VECTOR_HPP

typedef unsigned long long int uint64;
typedef signed long long int Index;
typedef uint64 Size;

#include <utility>
#include <algorithm>
#include <exception>
#include <iostream>

template <class T>
class Vector{
private:

    T ** _pData {nullptr} ;
    Size _capacity { 0ull };
    Size _size {0ull};

    using Value = T;
    using ValueReference = T &;
    using ValueConstReference = T const &;
    using Adrerss = T *;

    auto expandWith ( Size ) noexcept -> void;
    auto _resize    ( Size ) noexcept -> void;

public:

    Vector () noexcept = default;

    Vector ( Vector const &) noexcept;
    Vector ( Vector &&) noexcept;
    ~Vector();

    auto push           ( Value ) noexcept -> void;
    constexpr auto pop  () const noexcept -> Value { return this->_pData[_size];}

    auto remove         ( Index ) noexcept(false) -> void;
   // auto insert         ( ValueConstReference, Index ) noexcept(false) -> void;
    auto insert         ( Value, Index ) noexcept(false) -> void;

    auto get            ( Index ) const noexcept (false) -> ValueConstReference;
    auto set            ( ValueConstReference, Index ) noexcept(false) -> ValueConstReference;

    constexpr auto count () const noexcept -> uint64 { return this->_size; }
    constexpr auto size  () const noexcept -> uint64 { return this->_size; }
    constexpr auto print () const noexcept -> void;

    auto sort           (bool (* sortFunc) (ValueConstReference, ValueConstReference) noexcept) noexcept -> void;

    auto firstIndexOf   ( ValueConstReference obj, auto(* callbackFunction) (ValueConstReference, ValueConstReference) noexcept -> bool = nullptr) const noexcept -> Index{

        if ( callbackFunction == nullptr) {
            for (Index i = 0; i < this->_size; i++)
                if (obj[i] == this->_pData[i])
                    return i;
        }
        else {
            for (Index i = 0; i < this->_size; i++)
                if (callbackFunction(obj[i], _pData[i]))
                    return i;
        }
        return -1;
    }
};

template<class T>
Vector<T>::Vector(const Vector & obj) noexcept {
    this->_resize(obj._size);
    for (int i = 0; i < obj._size; ++i) {
        * this -> _pData [i] = *obj._pData[i];
        this->_capacity = obj._size;
    }
}

template<class T>
Vector<T>::Vector(Vector && moveObj) noexcept {
    this ->_pData = std::exchange(moveObj._pData, nullptr);
    this ->_size = std::exchange(moveObj._size, 0ull);
}

template<class T>
auto Vector<T>::push(Value value) noexcept -> void {
    this->expandWith( 1 );
    *this->_pData [ this -> _size++] = value;
}

template<class T>
auto Vector<T>::_resize(Size size) noexcept -> void {

    auto newMemory = new Adrerss [size];

    for( Index i = 0; i < size; i++){
        if ( i < this->_capacity)
            newMemory [i] = this->_pData[i];
        else
            newMemory [i] = new Value;
    }

    if (this -> _capacity > size)
        for(Index i = size; i < this->_capacity; i++)
            delete this -> _pData[i];

    delete [] this->_pData;
    this->_pData = newMemory;
    this->_capacity = size;
}

template<class T>
auto Vector<T>::expandWith( Size requiredSize) noexcept -> void {
    if ( this -> _size + requiredSize < this -> _capacity ) return;
    return this -> _resize(std::max(this->_size + requiredSize, this->_capacity * 2));
}

template<class T>
auto Vector<T>::remove(Index index) noexcept(false) -> void {
    if(index > this->_size)
        throw "Index out of bounds.";

    Vector without;

    for(Index i = 0, j = 0; i < this->_size; i++) {
        if (i != index)
            without._pData[j] = this->_pData[j], j++;
    }
    this->_pData = without;
    _size--;
}

template<class T>
auto Vector<T>::insert(Value obj, Index index) noexcept(false) -> void {
    if (index > this->_size)
        throw "Index out of bounds.";

    Vector with;
    with._capacity = this->_capacity;
    for(Index i = 0; i < index; i++)
        with._pData[i] = this ->_pData[i];

    with._pData[index] = &obj;

    for(Index i = index + 1; i < this->_size + 1; i++)
        with._pData[i] = this->_pData[i];

    this->_pData = with._pData;
    this->_size++;

}

template<class T>
Vector<T>::~Vector() {
    for ( Index i = 0; i < this->_capacity; i++ )
        delete this->_pData[i];
    delete [] this->_pData;
}

template<class T>
constexpr auto Vector<T>::print() const noexcept -> void {
    for(Index i = 0; i < this->_size; i++){
        std::cout << *_pData[i] << ' ';
    }
    std::cout << '\n';
}

template<class T>
auto Vector<T>::get(Index index) const noexcept(false) -> ValueConstReference {
    if (index < 0 || index > this->_size)
        throw "Index out of bounds.";
    return * this->_pData[index];
}

template<class T>
auto Vector<T>::set(ValueConstReference value, Index index) noexcept(false) -> ValueConstReference {
    if (index < 0 || index > this->_size)
        throw "Index out of bounds.";
    return *this->_pData[index] = value;
}

//TODO: implement sort function
template<class T>
auto Vector<T>::sort(bool (*sortFunc)(ValueConstReference, ValueConstReference) noexcept) noexcept -> void {
    if (sortFunc == nullptr) {
        return;
    }

}

#endif //LAB1_VECTOR_HPP
