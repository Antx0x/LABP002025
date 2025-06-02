class Sort
{
    // add data members
    int* vector;
    int c_size;
public:
    // add constuctors
    Sort(int elements, int min, int max);
    Sort(int size);
    Sort(int v[], int elements);
    Sort(int count, ...);
    Sort(char str[], int elements);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    ~Sort();
};