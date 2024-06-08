#include <iostream>
#include <cstring>
#include <cctype>
int mystrcmp(const char* str1, const char* str2) {
	size_t length1 = strlen(str1), length2 = strlen(str2);
	if (length1 == length2) {
		return 0;
	}
	else if (length1 > length2) {
		return 1;
	}
	else {
		return -1;
	}
}
int StringToNumber(char* str) {
	int new_number = atoi(str);
	std::cout << "The number from string: " << new_number;
	return new_number;
}
char* NumberToString(int number) {
    char buf[20];
    sprintf_s(buf, "%d", number);
    std::cout << buf;
    return buf;
}
char* Uppercase(char* str) {
    size_t len = strlen(str);
    char* result = new char[len + 1];
    for (int i = 0; i < len; i++) {
        result[i] = toupper(str[i]);
    }
    result[len] = '\0';
    return result;
}
char* Lowercase(char* str) {
    size_t len = strlen(str);
    char* result = new char[len + 1];
    for (int i = 0; i < len; i++) {
        result[i] = tolower(str[i]);
    }
    result[len] = '\0';
    return result;
}
char* mystrrev(char* str) {
    size_t len = strlen(str);
    char* result = new char[len + 1];
    for (int i = 0; i < len; i++) {
        result[i] = str[len - i - 1];
    }
    result[len] = '\0';
    return result;
}
int main() {
    const char* str_1 = "Programming";
    const char* str_2 = "Programmer";
    mystrcmp(str_1, str_2);
    std::cout << "\n\n";
    char*num_2=new char[50];
    std::cout << "Enter string number: ";
    std::cin >> num_2;
    StringToNumber(num_2);
    std::cout << "\n\n";
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;
    char* strNum = NumberToString(number);
    std::cout << "\n\n";
    char str_up[50];
    std::cout << "Enter string: ";
    std::cin >> str_up;
    char* upperStr = Uppercase(str_up);
    std::cout <<"Result: "<< upperStr;
    delete[]upperStr;
    std::cout << "\n\n";
    char str_lo[50];
    std::cout << "Enter string: ";
    std::cin >> str_lo;
    char* lowerStr = Lowercase(str_lo);
    std::cout << "Result: " << lowerStr;
    std::cout << "\n\n";
    char str_rev[50];
    std::cout << "Enter string: ";
    std::cin >> str_rev;
    char* revStr = mystrrev(str_rev);
    std::cout << "Result: " << revStr;
    return 0;
}