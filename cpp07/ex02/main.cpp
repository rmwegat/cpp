#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

int main() {
    std::cout << "=== Testing Array Class Template ===" << std::endl;
    
    try {
        // Test 1: Default constructor (empty array)
        std::cout << "\n1. Testing default constructor:" << std::endl;
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        
        // Test 2: Constructor with size parameter
        std::cout << "\n2. Testing constructor with size parameter:" << std::endl;
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;
        
        // Test default initialization (should be 0 for int)
        std::cout << "Default initialized values: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 3: Modifying elements using subscript operator
        std::cout << "\n3. Testing subscript operator (modification):" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = (i + 1) * 10;
        }
        std::cout << "Modified values: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 4: Copy constructor
        std::cout << "\n4. Testing copy constructor:" << std::endl;
        Array<int> copiedArray(intArray);
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        std::cout << "Copied array values: ";
        for (unsigned int i = 0; i < copiedArray.size(); i++) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 5: Independence of original and copy
        std::cout << "\n5. Testing independence of arrays after copying:" << std::endl;
        intArray[0] = 999;
        std::cout << "Original array[0] after modification: " << intArray[0] << std::endl;
        std::cout << "Copied array[0] (should be unchanged): " << copiedArray[0] << std::endl;
        
        // Test 6: Assignment operator
        std::cout << "\n6. Testing assignment operator:" << std::endl;
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "Assigned array values: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 7: Self-assignment protection
        std::cout << "\n7. Testing self-assignment:" << std::endl;
        assignedArray = assignedArray;
        std::cout << "Self-assignment completed without issues." << std::endl;
        std::cout << "Array size after self-assignment: " << assignedArray.size() << std::endl;
        
        // Test 8: String array
        std::cout << "\n8. Testing with string type:" << std::endl;
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "Array";
        std::cout << "String array: ";
        for (unsigned int i = 0; i < stringArray.size(); i++) {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 9: Const array and const subscript operator
        std::cout << "\n9. Testing const array:" << std::endl;
        const Array<int> constArray(copiedArray);
        std::cout << "Const array values: ";
        for (unsigned int i = 0; i < constArray.size(); i++) {
            std::cout << constArray[i] << " ";  // Uses const operator[]
        }
        std::cout << std::endl;
        
        // Test 10: Float array to test default initialization
        std::cout << "\n10. Testing float array default initialization:" << std::endl;
        Array<float> floatArray(4);
        std::cout << "Default float values: ";
        for (unsigned int i = 0; i < floatArray.size(); i++) {
            std::cout << floatArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Modify float array
        for (unsigned int i = 0; i < floatArray.size(); i++) {
            floatArray[i] = (i + 1) * 1.5f;
        }
        std::cout << "Modified float values: ";
        for (unsigned int i = 0; i < floatArray.size(); i++) {
            std::cout << floatArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 11: Exception handling - out of bounds access
        std::cout << "\n11. Testing exception handling:" << std::endl;
        try {
            std::cout << "Attempting to access index 10 in array of size 5..." << std::endl;
            std::cout << intArray[10] << std::endl;  // Should throw exception
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        // Test 12: Exception handling - empty array access
        try {
            std::cout << "Attempting to access index 0 in empty array..." << std::endl;
            std::cout << emptyArray[0] << std::endl;  // Should throw exception
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        // Test 13: Large array
        std::cout << "\n12. Testing large array:" << std::endl;
        Array<int> largeArray(1000);
        std::cout << "Large array created with size: " << largeArray.size() << std::endl;
        largeArray[999] = 42;
        std::cout << "Last element set to: " << largeArray[999] << std::endl;
        
        std::cout << "\n=== All tests completed successfully ===" << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}