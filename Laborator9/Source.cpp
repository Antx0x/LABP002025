#include <iostream>
#include <cstdio>
using namespace std;

template <typename K, typename V>
class Map {
private:
    struct Entry {
        K key;
        V value;
    };

    Entry* data;
    int size;
    int capacity;

    void resize() {
        capacity = capacity == 0 ? 4 : capacity * 2;
        Entry* newData = new Entry[capacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    int indexOfKey(const K& key) const {
        for (int i = 0; i < size; ++i)
            if (data[i].key == key)
                return i;
        return -1;
    }

public:
    Map() : data(nullptr), size(0), capacity(0) {}

    ~Map() {
        delete[] data;
    }

    V& operator[](const K& key) {
        int idx = indexOfKey(key);
        if (idx != -1) {
            return data[idx].value;
        }
        else {
            if (size == capacity) resize();
            data[size].key = key;
            data[size].value = V();  // Default value
            return data[size++].value;
        }
    }

    void Set(const K& key, const V& value) {
        int idx = indexOfKey(key);
        if (idx != -1) {
            data[idx].value = value;
        }
        else {
            if (size == capacity) resize();
            data[size].key = key;
            data[size].value = value;
            ++size;
        }
    }

    bool Get(const K& key, V& value) const {
        int idx = indexOfKey(key);
        if (idx != -1) {
            value = data[idx].value;
            return true;
        }
        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    bool Delete(const K& key) {
        int idx = indexOfKey(key);
        if (idx != -1) {
            for (int i = idx; i < size - 1; ++i)
                data[i] = data[i + 1];
            --size;
            return true;
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        for (int i = 0; i < other.size; ++i) {
            V value;
            if (!Get(other.data[i].key, value) || !(value == other.data[i].value))
                return false;
        }
        return true;
    }

    struct Iterator {
        Entry* ptr;
        int index;

        Iterator(Entry* p, int i) : ptr(p), index(i) {}

        Iterator& operator++() {
            ++ptr;
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        auto operator*() const {
            return std::tuple<K&, int, V&>(ptr->key, index,ptr->value);
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data + size, size);
    }
};


int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, index,  value] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, index, value] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
