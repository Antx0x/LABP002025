#include "Number.h"
#include <cstring>
#include <iostream>
#include <algorithm>

Number operator+(const Number& lhs, const Number& rhs)
{
    int sum = lhs.toDecimal() + rhs.toDecimal();
    Number result(sum);
    result.SwitchBase(16);
    return result;
}

Number operator-(const Number& lhs, const Number& rhs)
{
    int sum = lhs.toDecimal() - rhs.toDecimal();
    Number result(sum);
    result.SwitchBase(16);
    return result;
}



Number::Number(const char* value, int base)
{
    str = new char[strlen(value) + 1];
    strcpy_s(str, strlen(value) + 1, value);
    base_c = base;
}

Number::Number(int value)
{
    base_c = 10; // Default to base 10
    char buffer[65];
    _itoa_s(value, buffer, 10); // Convert int to base 10 string
    str = new char[strlen(buffer) + 1];
    strcpy_s(str, strlen(buffer) + 1, buffer);
}


void Number::SwitchBase(int newBase) {

    int decimalValue = strtol(str, nullptr, base_c);

    char buffer[65];

    int index = 0;
    int temp = decimalValue;
    if (temp == 0) {
        buffer[index++] = '0';
    }
    else {
        while (temp > 0) {
            int digit = temp % newBase;
            buffer[index++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
            temp /= newBase;
        }
    }

    buffer[index] = '\0';

    for (int i = 0; i < index / 2; ++i)
        std::swap(buffer[i], buffer[index - i - 1]);

    delete[] str;
    str = new char[index + 1];
    strcpy_s(str, index + 1, buffer);
    base_c = newBase;
}

void Number::Print()
{
    std::cout << "Number: " << str << ", in the base: " << base_c << std::endl;
}

int Number::GetDigitsCount()
{
    return strlen(str);
}

int Number::GetBase()
{
    return base_c;
}

Number::~Number()
{
   // std::cout << "Destructor apelat!\n";
    delete[] str;
    str = nullptr;
}
