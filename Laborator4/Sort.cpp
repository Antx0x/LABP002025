#include "Sort.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstdarg>

Sort::Sort(int numElements, int minVal, int maxVal) {
    c_size = numElements;
    vector = new int[c_size];
    srand(time(0));
    for (int i = 0; i < c_size; i++) {
        vector[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

Sort::Sort(int size){
    c_size = size;
    vector = new int[c_size];  
    for (int i = 0; i < c_size; ++i)
        vector[i] = i + 1;
}

Sort::Sort(int v[], int Elements) {
    c_size = Elements;
    vector = new int[c_size];
    for (int i = 0; i < c_size; i++)
        vector[i] = v[i];
}

Sort::Sort(int count, ...){
    c_size = count;
    vector = new int[c_size];   

    va_list args;
    va_start(args, count);   

    for (int i = 0; i < c_size; i++) {
        vector[i] = va_arg(args, int);   
    }

    va_end(args);   
}

Sort::Sort(char str[], int elements){
    int count = 0;
    vector = new int[elements];
    for (int i = 0; i < elements; i++)
    {
        int number = 0;
        while (str[i] != ',' && str[i] != '\0') {
            int x = str[i] - '0';
            number = number * 10 + x;
            i++;
        }
        vector[count++] = number;
    }
    c_size = count ;
}

void Sort::InsertSort(bool ascendent){
    if(ascendent)
        for (int i = 1; i < c_size; i++)
        {
            int p = i;
            while (p > 0 && vector[p] < vector[p - 1])
            {
                int aux = vector[p];
                vector[p] = vector[p - 1];
                vector[p - 1] = aux;
                p--;
            }
        }
    else
        for (int i = 1; i < c_size; i++)
        {
            int p = i;
            while (p > 0 && vector[p] > vector[p - 1])
            {
                int aux = vector[p];
                vector[p] = vector[p - 1];
                vector[p - 1] = aux;
                p--;
            }
        }
}

int Partition(int arr[], int low, int high, bool ascendent) {
    int pivot = arr[high]; 
    int i = low - 1;      

    for (int j = low; j < high; j++) {
        if ((ascendent && arr[j] < pivot) || (!ascendent && arr[j] > pivot)) {
            i++;
            std::swap(arr[i], arr[j]); 
        }
    }

    std::swap(arr[i + 1], arr[high]); 
    return i + 1; 
}

void QuickSort_f(int arr[], int low, int high, bool ascendent = true) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high, ascendent);
        QuickSort_f(arr, low, pivotIndex - 1, ascendent);  
        QuickSort_f(arr, pivotIndex + 1, high, ascendent); 
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSort_f(vector, 0, c_size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent){
    for (int i = 0; i < c_size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < c_size - i - 1; j++) {
            if ((ascendent && vector[j] > vector[j + 1]) || (!ascendent && vector[j] < vector[j + 1])) {
                std::swap(vector[j], vector[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void Sort::Print() {
    for (int i = 0; i < c_size; i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount()
{
    return c_size;
}

int Sort::GetElementFromIndex(int index)
{
    return vector[index];
}

Sort::~Sort() {
    std::cout << "Destructor apelat!\n";
    delete[] vector;
}

