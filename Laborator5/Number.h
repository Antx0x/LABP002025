#include <cstring>
#include <cstdlib>

class Number
{
	char* str;
	int base_c;
	int toDecimal() const {
		return strtol(str, nullptr, base_c);  // Convert str from base_c to decimal
	}
public:
	Number(const char* value, int base);  
	Number(int value);

	Number(const Number& other) {
		base_c = other.base_c;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
	}

	Number& operator=(const Number& other) {
		if (this != &other) {
			delete[] str;
			base_c = other.base_c;
			str = new char[strlen(other.str) + 1];
			strcpy_s(str, strlen(other.str) + 1, other.str);
		}
		return *this;
	}
	~Number();

	char operator[](int index) const {
		if (index >= 0 && index < strlen(str)) 
			return str[index];  
		return '?';  
	}

	friend Number operator+(const Number& lhs, const Number& rhs);
	friend Number operator-(const Number& lhs, const Number& rhs);
 
	bool operator>(const Number& other) const {
		return this->toDecimal() > other.toDecimal();
	}

	Number& operator=(int value) {
		char buffer[65];
		_itoa_s(value, buffer, 10);  
		delete[] str;
		str = new char[strlen(buffer) + 1];
		strcpy_s(str, strlen(buffer) + 1, buffer);
		base_c = 10;
		return *this;
	}

	Number& operator=(const char* value) {
		delete[] str;
		str = new char[strlen(value) + 1];
		strcpy_s(str, strlen(value) + 1, value);
		return *this;
	}

	Number& operator+=(const Number& other) {
		int sum = this->toDecimal() + other.toDecimal();
		char buffer[65];
		_itoa_s(sum, buffer, base_c);  
		delete[] str;
		str = new char[strlen(buffer) + 1];
		strcpy_s(str, strlen(buffer) + 1, buffer);
		return *this;
	}


	Number& operator--() {
		int len = strlen(str);
		if (len <= 1) {
			strcpy_s(str, 2, "0");
		}
		else {
			memmove(str, str + 1, len); // shift string left
		}
		return *this;
	}

	
	Number operator--(int) {
		Number temp = *this; 
		int len = strlen(str);
		if (len <= 1) {
			strcpy_s(str, 2, "0");
		}
		else {
			str[len - 1] = '\0'; // remove last character
		}
		return temp;
	}

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base;
};

