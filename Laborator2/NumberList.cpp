#include <iostream>
#include <algorithm> 
#include "NumberList.h"


void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if (count < 10) {
        numbers[count] = x;
        count++;
        return true;
    }
    return false; 
}

void NumberList::Sort() {
    std::sort(numbers, numbers + count); 
}

void NumberList::Print() {
    if (count == 0) {
        std::cout << "The list is empty!" << std::endl;
        return;
    }
    std::cout << "Current numbers in the list: ";
    for (int i = 0; i < count; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}
