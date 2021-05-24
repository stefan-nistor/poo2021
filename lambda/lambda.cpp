#include <utility>
#include <algorithm>
#include <exception>
#include <iostream>
#include <initializer_list>
class MyVector {
private:

    int **_pData{nullptr};
    int _capacity{0ull};
    int _size{0ull};

    using Value = int;
    using ValueReference = int &;
    using ValueConstReference = int const &;
    using Adrerss = int *;

    auto expandWith (int) noexcept -> void;
    auto _resize    (int) noexcept -> void;

public:



    MyVector() noexcept = default;
    MyVector (MyVector const &) noexcept;

    MyVector (std::initializer_list<int> const& ref) noexcept { for (const auto &item : ref) this->Add(item);}

    auto Add    (Value) noexcept -> bool;
    auto Delete (int) noexcept(false) -> bool;

    auto begin  ()  const noexcept {return *this->_pData[0];}
    auto end    ()    const noexcept {return *this->_pData[this->_size];}

    auto Iterate    (int (*)(int)) noexcept -> void;
    auto Filter     (bool (*f)(int)) noexcept -> void;

    friend std::ostream& operator<< (std::ostream& buf, MyVector const & v) noexcept {
        for (int i = 0; i < v._size; i++)
            buf << (*v._pData[i]) << ' ';
        return buf;
    }

};

auto MyVector::Add(MyVector::Value value) noexcept -> bool {
    this->expandWith( 1 );
    *this->_pData [ this -> _size++] = value;
    return true;
}

auto MyVector::Delete(int index) noexcept(false) -> bool {
    if(index < 0 || index > this->_size)
        throw "Index out of bounds";

    MyVector temp;
    for(int i = 0, j = 0; i < this->_size; i++){
        if(i != index)
            *temp._pData = this->_pData[j], j++;
    }
    this->_pData = temp._pData;
    _size--;
}

MyVector::MyVector(const MyVector & o) noexcept {
    this->_resize(o._size);
    for(int i = 0; i < o._size; i++){
        *this->_pData[i] = *o._pData[i];
        this->_capacity = o._size;
    }
}

auto MyVector::expandWith(int reqSize) noexcept -> void {
    if (this->_size + reqSize < this->_capacity) return;
    return this ->_resize(std::max(this->_size + reqSize, this->_capacity *2));
}

auto MyVector::_resize(int size) noexcept -> void {
    auto newMem = new int *[size];

    for(int i = 0; i < size; i++){
        if (i < this->_capacity)
            newMem[i] = this->_pData[i];
        else
            newMem[i] = new int;
    }

    if (this->_capacity > size)
        for(int i = size; i < this->_capacity; i++)
            delete this->_pData[i];

    delete [] this->_pData;
    this->_pData = newMem;
    this->_capacity = size;
}

auto MyVector::Iterate(int (*f)(int)) noexcept -> void {
    for(int i = 0; i < this->_size; i++)
        *this->_pData[i] = f(*this->_pData[i]);
}

auto MyVector::Filter(bool (*f)(int)) noexcept -> void {
    for( int i = 0; i < this->_size; i++){
        if(f(*this->_pData[i]))
            Delete(i);
    }
}

#include <vector>
using namespace std;
MyVector v = {1, 4 ,6, 12, 243, 632, 12 ,432 ,53, 12};
int main(){

    vector<string> arr;
    std::sort(std::begin(arr),std::end(arr), [](string a, string b) {return a.length() > b.length();});
    std::sort(std::begin(arr),std::end(arr), [](string a, string b) {return a > b;});

    int max = INT32_MIN;
    auto big = [max] (vector<int> a) mutable { for(auto it : a) if(a[it] > max) max = a[it];};

    MyVector v;

    auto f1 = [](int x) noexcept -> bool {return x == 12;};
    auto f2 = [](int x) noexcept -> int  {return x + 12;};

    ::v.Filter(f1);
    ::v.Iterate(f2);

    std::cout << ::v;

    return 0;
}
