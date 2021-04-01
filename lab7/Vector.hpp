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
#include <cstring>
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
    using Address = T *;

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
    auto insert         ( Value, Index ) noexcept(false) -> void;

    auto get            ( Index ) const noexcept (false) -> ValueConstReference;
    auto set            ( ValueConstReference, Index ) noexcept(false) -> ValueConstReference;

    constexpr auto count () const noexcept -> Size { return this->_size; }
    constexpr auto size  () const noexcept -> Size { return this->_size; }
    constexpr auto print () const noexcept -> void;

    auto sort           (int (* sortFunc) (ValueConstReference, ValueConstReference) noexcept = nullptr ) noexcept -> void;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"
    auto firstIndexOf   ( ValueConstReference obj, auto(* callbackFunction) (ValueConstReference, ValueConstReference) noexcept -> bool = nullptr) const noexcept-> Index;
#pragma clang diagnostic pop

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

    auto newMemory = new Address [size];

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
        throw std::runtime_error("Index out of bounds.");

    auto without = new Address[this->_capacity];
    memset(without, 0, sizeof(std::size_t) * this->_capacity);

    for(Index i = 0, j = 0; i < this->_size; i++) {
        if (i != index)
            without[j++] = this->_pData[i];
    }
    this->_pData = without;
    this->_size--;
}

template<class T>
auto Vector<T>::insert(Value obj, Index index) noexcept(false) -> void {
    if (index > this->_size)
        throw std::runtime_error("Out of bounds");
    else if ( index == this->_size && index == this->_capacity )
        this->_resize(this->_size + 1);

    auto with = new Address[this->_capacity];
    memset(with, 0, sizeof(std::size_t) * this->_capacity);

    for(Index i = 0; i < index; i++)
        with[i] = this->_pData[i];

    with[index] = new T(obj);

    for(Index i = index + 1; i < this->_size + 1; i++)
        with[i] = this->_pData[i - 1];

    for(Index i = this->_size + 1; i < this->_capacity - 1; i++)
        with[i + 1] = this->_pData[i];

    delete [] this->_pData;

    this->_pData = with;
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
        throw std::runtime_error("Index out of bounds.");
    return * this->_pData[index];
}

template<class T>
auto Vector<T>::set(ValueConstReference value, Index index) noexcept(false) -> ValueConstReference {
    if (index < 0 || index > this->_size)
        throw std::runtime_error("Index out of bounds.");
    return *this->_pData[index] = value;
}

template<class T>
auto Vector<T>::firstIndexOf(ValueConstReference obj, auto (*callbackFunction)(ValueConstReference, ValueConstReference) noexcept -> bool) const noexcept -> Index {

    if ( callbackFunction == nullptr) {
        for (Index i = 0; i < this->_size; i++)
            if (obj == *this->_pData[i])
                return i;
    }
    else {
        for (Index i = 0; i < this->_size; i++)
            if (callbackFunction(obj, *_pData[i]))
                return i;
    }
    return -1;
}


template<class T>
auto Vector<T>::sort(int (*sortFunc)(ValueConstReference , ValueConstReference ) noexcept) noexcept -> void {
    for (Index i = 0; i < this->_size - 1; i++) {
        for (Index j = 0; j < this->_size - 1 - i; j++) {
            if (sortFunc != nullptr) {
                if (sortFunc(*this->_pData[j], *this->_pData[j + 1])) {
                    Address aux = this->_pData[j];
                    this->_pData[j] = this->_pData[j + 1];
                    this->_pData[j + 1] = aux;
                }
            } else if (this->_pData[j] < this->_pData[j + 1]) {
                Address aux = this->_pData[j];
                this->_pData[j] = this->_pData[j + 1];
                this->_pData[j + 1] = aux;
            }
        }
    }
}

#endif //LAB1_VECTOR_HPP
