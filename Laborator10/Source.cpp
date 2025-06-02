#include <exception>
#include <iostream>
#include <algorithm>

using namespace std;

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

class CompareInts : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int a = *(int*)e1,
            b = *(int*)e2;
        if (a < b)
            return -1;
        else if (a == b)
            return 0;
        return 1;
    }
};

int CompareIntsFunc(const int& a, const int& b) {
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    return 1;
}

class exceptie1 : public exception {
    const char* what() const throw() override {
        return "Index in afara limitelor!";
    }
} outIndex; // obiect

class exceptie2 : public exception {
    const char* what() const throw() override {
        return "Array-ul este full!";
    }
} fullArray; // obiect

template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current;
    int Size;
public:
    ArrayIterator() : List(nullptr), Current(0), Size(0) {}
    ArrayIterator(T** list, int index, int size) : List(list), Current(index), Size(size) {}

    ArrayIterator& operator ++ () {
        ++Current;
        return *this;
    }

    ArrayIterator& operator -- () {
        --Current;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return this->List == other.List && this->Current == other.Current;
    }
    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }

    T& operator*() {
        if (List == nullptr || Current < 0 || Current >= Size)
            throw outIndex;
        return *List[Current];
    }

    T* GetElement() {
        if (List == nullptr || Current < 0 || Current >= Size)
            throw outIndex;
        return List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    ~Array() {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }

    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
    }

    Array<T>& operator=(const Array<T>& otherArray) {
        if (this != &otherArray) {
            for (int i = 0; i < Size; i++)
                delete List[i];
            delete[] List;

            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T * [Capacity];
            for (int i = 0; i < Size; i++)
                List[i] = new T(*otherArray.List[i]);
        }
        return *this;
    }

    T& operator[] (int index) {
        if (index < 0 || index >= Size)
            throw outIndex;
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity)
            throw fullArray;
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size)
            throw outIndex;
        if (Size >= Capacity)
            throw fullArray;
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray) {
        if (index < 0 || index > Size)
            throw outIndex;
        if (Size + otherArray.Size > Capacity)
            throw fullArray;
        for (int i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size)
            throw outIndex;
        delete List[index];
        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;
    }

    void Sort() {
        if (Size < 2) return;
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                    swap(List[i], List[j]);
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(List[i], List[j]);
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            else if (*List[mid] > elem)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = compare(*List[mid], elem);
            if (cmp == 0)
                return mid;
            else if (cmp > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = comparator->CompareElements(List[mid], (void*)&elem);
            if (cmp == 0)
                return mid;
            else if (cmp > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
        return -1;
    }

    int GetSize() const {
        return Size;
    }

    int GetCapacity() const {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, 0, Size);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size, Size);
    }
};

int main() {
    try {
        Array<int> arr(5);
        arr += 10;
        arr += 20;
        arr += 30;

        cout << "Elementele din Array prin iterare:" << endl;
        for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    return 0;
}