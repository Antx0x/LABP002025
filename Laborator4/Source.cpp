#include "Sort.h"
#include <iostream>
#include <cstring>

int main() {

	Sort s1(10, 1, 100);
	std::cout << "Random elements: ";
	s1.Print();
	s1.InsertSort(true);
	std::cout << "Random elements sorted: ";
	s1.Print();
  /*
	Sort s2();
	std::cout << "Initializer list: ";
	s2.Print();
	s2.InsertSort(true);
	std::cout << "Initializer list sorted: ";
	s2.Print();
	*/
	 	
	int vector[] = { 10, 4, 2, 3, 1, 0 };
	Sort s3(vector, 6);
	std::cout << "Existing array: ";
	s3.Print();
	s3.BubbleSort(true);
	std::cout << "Existing array sorted: ";
	s3.Print();

	Sort s4(4, 10, 30, 20, 50);
	std::cout << "Variadic elements: ";
	s4.Print();
	s4.QuickSort(true);
	std::cout << "Variadic elements sorted: ";
	s4.Print();

	char str[] = "10,40,100,5,70";
	int elements = strlen(str);
	Sort s5(str, elements);
	std::cout << "String list: ";
	s5.Print();
	s5.InsertSort(true);
	std::cout << "String list converted and sorted: ";
	s5.Print();

	return 0;
}