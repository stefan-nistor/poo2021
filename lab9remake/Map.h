//
// Created by Stefan on 4/21/2021.
//

#ifndef LAB1_MAP_H
#define LAB1_MAP_H

template<typename K, typename  V>
class DataEntry{
public:
    K k;
    V v;
    explicit DataEntry(const K& key = K(), const V& val = V()) : k(key), v(val) {}
    constexpr auto getValue() const noexcept {return this->v;}
};

template<typename K, typename V>
class Map{
private:
    unsigned int current_size;
    DataEntry<K,V> arr[100];
public:

    class MyIterator{
        DataEntry<K,V> * d;
        unsigned int index;
    public:
        MyIterator(DataEntry<K,V>* d, unsigned int index) : d(d), index(index) {}

        constexpr MyIterator& operator++() noexcept                {index++; return *this;}
        constexpr auto operator!=(MyIterator it) const noexcept    {return this->index != it.index;}
        constexpr auto operator*() const noexcept                  {return d[index];}
        constexpr auto getKey() const noexcept                     {return this->d->k;}
        constexpr auto getValue() const noexcept                   {return this->d->v;}
    };

    Map() {current_size = 0;}


    constexpr auto begin() const noexcept      {return MyIterator(arr,0);}
    constexpr auto end() const noexcept        {return MyIterator(arr,current_size);}

    inline auto set(const K & key, const V& value) noexcept -> void {
        arr[key] = DataEntry(key, value);
        ++current_size;
    }

    auto operator[] (const K& key) const noexcept -> V&;

    auto get(const K& key, V& value) noexcept(false) -> bool;
    auto clear() noexcept -> void;
    auto remove(const K&) noexcept(false) -> bool;
    constexpr auto includes (const Map<K,V>&) const noexcept -> bool;


    constexpr inline auto count() const noexcept {return this->current_size;}
};

template<typename K, typename V>
auto Map<K, V>::operator[](const K &key) const noexcept -> V & {
    return ;
}

#endif //LAB1_MAP_H
