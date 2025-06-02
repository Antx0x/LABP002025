#include "Math.h"
#include <cstdarg>  // Required for variadic functions
#include <cstring>

int Math::Add(int a, int b){
    return a + b;
}

int Math::Add(int a, int b , int c){
    return a + b + c;
}

int Math::Add(double a, double b){
    return a + b;
}

int Math::Add(double a, double b, double c){
    return a + b + c;
}

int Math::Mul(int a, int b){
    return a * b;
}

int Math::Mul(int a, int b, int c){
    return a * b * c;
}

int Math::Mul(double a, double b){
    return a * b;
}

int Math::Mul(double a, double b, double c){
    return a * b * c;
}

int Math::Add(int count, ...){
    va_list args;
    va_start(args, count); // Start extracting arguments

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int); // Get the next argument
    }
    va_end(args); // Clean up
    return sum;
}

char* Math::Add(const char* str1, const char* str2){
    int len1 = std::strlen(str1);
    int len2 = std::strlen(str2);

    // Allocate memory for the concatenated string (+1 for the null terminator)
    char* result = new char[len1 + len2 + 1]; // +1 for the '\0' at the end

    // Copy the first string to result
    strcpy_s(result, len1+len2+1, str1);

    // Append the second string to result
     strcat_s(result,len1+len2+1, str2);

    return result;  // The caller is responsible for freeing the memory
}