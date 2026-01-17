#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

int main() {
    std::cout << "=== Testing Array Class Template ===" << std::endl;
    
    try {
        // Test 1: Constructor with size
        std::cout << "\n1. Testing constructor:" << std::endl;
        Array<int> intArray(5);
        std::cout << "Array size: " << intArray.size() << std::endl;
        
        // Test 2: Subscript operator (modification and access)
        std::cout << "\n2. Testing subscript operator:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = (i + 1) * 10;
        }
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 3: Copy constructor
        std::cout << "\n3. Testing copy constructor:" << std::endl;
        Array<int> copiedArray(intArray);
        intArray[0] = 999;
        std::cout << "Original[0]: " << intArray[0] << ", Copy[0]: " << copiedArray[0] << std::endl;
        
        // Test 4: Assignment operator
        std::cout << "\n4. Testing assignment operator:" << std::endl;
        Array<int> assignedArray;
        assignedArray = intArray;
        assignedArray = assignedArray;  // Self-assignment test
        std::cout << "Assignment successful, size: " << assignedArray.size() << std::endl;
        
        // Test 5: Exception handling
        std::cout << "\n5. Testing exception handling:" << std::endl;
        try {
            std::cout << intArray[10] << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n=== All tests completed ===" << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
