//
// Created by Stefan on 4/29/2021.
//

#ifndef LAB1_ARRAY_H
#define LAB1_ARRAY_H
#include <exception>
#include <algorithm>
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:

    ArrayIterator() noexcept = default;

    constexpr auto next () noexcept -> ArrayIterator & final { this->Current ++; return * this; }
    constexpr auto prev () noexcept -> ArrayIterator & { this->Current --; return * this; }

    constexpr auto operator ++ () noexcept -> ArrayIterator& {return this -> next();}
    constexpr auto operator -- () noexcept -> ArrayIterator& {return this -> prev();}

    constexpr auto operator = (ArrayIterator const & o) noexcept ->ArrayIterator& {
        this->Current = o.Current;
        return *this;
    }

    inline auto operator != (ArrayIterator const & o) noexcept -> bool {return this->Current == o.Current;}

    constexpr auto GetElement() const noexcept -> T*;
};

class IndexException : public std::exception{
public:
    [[nodiscard]] auto what() const noexcept -> const char * override{
        return "Invalid index.\n";
    }
};

class SizeException : public std::exception {
public:
    auto what () const noexcept -> const char * override{
        return "Requested size too large.\n";
    }
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity{}; // dimensiunea listei de pointeri
    int Size{}; // cate elemente sunt in lista


    auto Resize (int size) noexcept -> void;
public:
    Array() noexcept: Capacity(0), Size(0), List{nullptr} {}; // Lista nu e alocata, Capacity si Size = 0
    ~Array() noexcept; // destructor
    explicit Array(int capacity) noexcept: Capacity(capacity) {}; // Lista e alocata cu 'capacity' elemente
    Array(const Array<T> &otherArray) noexcept; // constructor de copiere


    auto expandWith (int size) noexcept -> void {
        if (this->Size + size < this -> Capacity)
            throw SizeException();
        return this->Resize(std::max(this->Size + size, this->Capacity * 2));
    }

    constexpr auto size() const noexcept -> int {return this->Size;}

    auto push(T value) noexcept -> T* {
        this->expandWith(1);
        return *this->List[this->Size++] = value;
    }


    T& operator[] (int index) noexcept(false); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator

    inline auto GetSize()       const noexcept -> int {return this->Size;}
    inline auto GetCapacity()   const noexcept -> int {return this->Capacity;}

    ArrayIterator<T> GetBeginIterator() {return ArrayIterator(this, 0);}
    ArrayIterator<T> GetEndIterator()   {return ArrayIterator(this, this->size());}
};

template<class T>
Array<T>::Array(const Array<T> &otherArray) noexcept {
    this->Resize(otherArray.Size);
    for(int i = 0; i < otherArray.Size; ++i){
        *this->List[i] = *otherArray.List[i];
        this->Capacity = otherArray.Size;
    }
}

template<class T>
auto Array<T>::Resize(int size) noexcept -> void {
    auto newMemory = new T* [size];

    for(int i = 0; i < size; i++){
        if ( i < this->Capacity)
            newMemory[i] = this->List[i];
        else
            newMemory[i] = new T;
    }

    if (this->Capacity > size)
        for(int i = size; i < this->Capacity; i++)
            delete this->List[i];

    delete [] this->List;
    this->List = newMemory;
    this->Capacity = size;

}

template<class T>
Array<T>::~Array() noexcept {
    for(int i = 0; i < this->Capacity; i++)
        delete this->List[i];
    delete [] this->List;
}

template<class T>
T &Array<T>::operator[](int index) noexcept(false) {
    if (index > this->Size || index < 0)
        throw IndexException();

    return *this->List[index];
}

template<class T>
const Array<T> &Array<T>::Insert(int index, const T newElem) {
    if (index > this->size || index < 0)
        throw IndexException();
    return *this->List[index] = newElem;
}

template<class T>
const Array<T> &Array<T>::Insert(int index, const Array<T> otherArray) {
    if (index > this->Size || index < 0)
        throw IndexException();
}

template<class T>
const Array<T> &Array<T>::Delete(int index) {
    if (index > this->Size || index < 0)
        throw IndexException();


}

template<class T>
int Array<T>::Find(const T &elem, Compare *comparator) {
    if (comparator == nullptr){
        for(int i = 0; i < this->Size; i++)
            if(elem[i] == this->List[i])
                return i;
    }
    else{
        for(int i = 0; i < this->Size; i++)
            if(comparator->CompareElements(elem[i], List[i]))
                return i;
    }

    return -1;
}

template<class T>
const Array<T> &Array<T>::operator+=(const T &newElem) {
    push(newElem);
    return *this;
}

#endif //LAB1_ARRAY_H
