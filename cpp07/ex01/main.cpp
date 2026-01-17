#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& element) {
    std::cout << element << " ";
}

void doubleInt(int& n) {
    n *= 2;
}

void toUpper(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

int main() {
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test 1: Integer array
    std::cout << "\n1. Integer array:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Original: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, doubleInt);
    std::cout << "After doubling: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    // Test 2: String array
    std::cout << "\n2. String array:" << std::endl;
    std::string strArray[] = {"hello", "world"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    std::cout << "Original: ";
    iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;
    
    iter(strArray, strSize, toUpper);
    std::cout << "After uppercase: ";
    iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}
