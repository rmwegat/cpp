#include <iostream>
#include <string>
#include "iter.hpp"

// Test functions for different scenarios

// Function to print any type (works with const references)
template <typename T>
void print(const T& element) {
    std::cout << element << " ";
}

// Function to double an integer (works with non-const references)
void doubleInt(int& n) {
    n *= 2;
}

// Function to increment an integer (works with non-const references)
void increment(int& n) {
    n++;
}

// Function to make string uppercase (works with non-const references)
void toUpper(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

// Function to print string length (works with const references)
void printLength(const std::string& str) {
    std::cout << "[" << str.length() << "] ";
}

// Function template that can be instantiated
template <typename T>
void printSquare(const T& element) {
    std::cout << element * element << " ";
}

int main() {
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test 1: Integer array with print function
    std::cout << "\n1. Integer array with print function:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Original: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    // Test 2: Integer array with doubling function (modifies array)
    std::cout << "\n2. Integer array with doubling function:" << std::endl;
    iter(intArray, intSize, doubleInt);
    std::cout << "After doubling: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    // Test 3: Integer array with increment function
    std::cout << "\n3. Integer array with increment function:" << std::endl;
    iter(intArray, intSize, increment);
    std::cout << "After increment: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    // Test 4: Const integer array (read-only operations)
    std::cout << "\n4. Const integer array with print and square functions:" << std::endl;
    const int constArray[] = {1, 2, 3, 4, 5};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);
    std::cout << "Original: ";
    iter(constArray, constSize, print<int>);
    std::cout << std::endl;
    std::cout << "Squares: ";
    iter(constArray, constSize, printSquare<int>);
    std::cout << std::endl;
    
    // Test 5: String array with print function
    std::cout << "\n5. String array with print function:" << std::endl;
    std::string strArray[] = {"hello", "world", "cpp", "templates"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    std::cout << "Original: ";
    iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;
    
    // Test 6: String array with length function
    std::cout << "\n6. String array with length function:" << std::endl;
    std::cout << "Lengths: ";
    iter(strArray, strSize, printLength);
    std::cout << std::endl;
    
    // Test 7: String array with uppercase function (modifies array)
    std::cout << "\n7. String array with uppercase function:" << std::endl;
    iter(strArray, strSize, toUpper);
    std::cout << "After uppercase: ";
    iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;
    
    // Test 8: Float array
    std::cout << "\n8. Float array:" << std::endl;
    float floatArray[] = {1.5f, 2.7f, 3.14f, 4.2f};
    size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "Float values: ";
    iter(floatArray, floatSize, print<float>);
    std::cout << std::endl;
    std::cout << "Float squares: ";
    iter(floatArray, floatSize, printSquare<float>);
    std::cout << std::endl;
    
    // Test 9: Character array
    std::cout << "\n9. Character array:" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Characters: ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}