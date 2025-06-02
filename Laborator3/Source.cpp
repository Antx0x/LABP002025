#include <iostream>
#include "Math.h"

int main() {

	std::cout << "Add 2 int: " << Math::Add(3, 5) << std::endl;
	std::cout << "Add 3 int: " << Math::Add(3, 5, 10) << std::endl;
	std::cout << "Add 2 double: " << Math::Add(3.1, 5.3) << std::endl;
	std::cout << "Add 3 double: " << Math::Add(3.1, 5.3, 10.12) << std::endl;
	std::cout << "Mul 2 int: " << Math::Mul(3, 5) << std::endl;
	std::cout << "Mul 3 int: " << Math::Mul(3, 5, 10) << std::endl;
	std::cout << "Mul 2 double: " << Math::Mul(3.2, 5.4) << std::endl;
	std::cout << "Mul 3 double: " << Math::Mul(3.2, 5.4, 10.3) << std::endl;
	std::cout << "Add infinit numbers: " << Math::Add(6, 2, 2, 2, 2, 2, 2) << std::endl;
	char A[20] = "Word";
	char B[20] = "File";
	std::cout << "Add 2 strings: " << Math::Add(A, B) << std::endl;
}