#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

#define COLOR_RESET   "\033[0m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"

void printData(const Data& data) {
    std::cout << "  ID: " << data.id << std::endl;
    std::cout << "  Name: " << data.name << std::endl;
    std::cout << "  Value: " << data.value << std::endl;
    std::cout << "  Active: " << (data.active ? "true" : "false") << std::endl;
}

int main() {
    std::cout << COLOR_YELLOW << "=== Serialization Testing ===" << COLOR_RESET << std::endl;

    // Create a Data object
    std::cout << COLOR_YELLOW << "\n1. Creating Data object:" << COLOR_RESET << std::endl;
    Data originalData(42, "Test Object", 3.14159, true);
    Data* originalPtr = &originalData;
    
    std::cout << "Original Data object:" << std::endl;
    printData(originalData);
    std::cout << "Original pointer address: " << originalPtr << std::endl;

    // Serialize the pointer
    std::cout << COLOR_YELLOW << "\n2. Serializing pointer:" << COLOR_RESET << std::endl;
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: 0x" << std::hex << serialized << std::dec << std::endl;
    std::cout << "Serialized value (decimal): " << serialized << std::endl;

    // Deserialize back to pointer
    std::cout << COLOR_YELLOW << "\n3. Deserializing back to pointer:" << COLOR_RESET << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;

    // Verify the pointers are equal
    std::cout << COLOR_YELLOW << "\n4. Verification:" << COLOR_RESET << std::endl;
    if (originalPtr == deserializedPtr) {
        std::cout << COLOR_GREEN << "✓ SUCCESS: Pointers match!" << COLOR_RESET << std::endl;
    } else {
        std::cout << COLOR_RED << "✗ FAILURE: Pointers don't match!" << COLOR_RESET << std::endl;
        return 1;
    }

    // Verify the data is accessible through deserialized pointer
    std::cout << COLOR_YELLOW << "\n5. Data accessibility test:" << COLOR_RESET << std::endl;
    std::cout << "Data through deserialized pointer:" << std::endl;
    printData(*deserializedPtr);

    // Verify data integrity
    if (deserializedPtr->id == originalData.id &&
        deserializedPtr->name == originalData.name &&
        deserializedPtr->value == originalData.value &&
        deserializedPtr->active == originalData.active) {
        std::cout << COLOR_GREEN << "✓ SUCCESS: Data integrity maintained!" << COLOR_RESET << std::endl;
    } else {
        std::cout << COLOR_RED << "✗ FAILURE: Data corruption detected!" << COLOR_RESET << std::endl;
        return 1;
    }

    // Test with different Data objects
    std::cout << COLOR_YELLOW << "\n6. Testing with multiple objects:" << COLOR_RESET << std::endl;
    Data data1(1, "First", 1.11, false);
    Data data2(2, "Second", 2.22, true);
    Data data3(3, "Third", 3.33, false);

    Data* ptr1 = &data1;
    Data* ptr2 = &data2;
    Data* ptr3 = &data3;

    uintptr_t ser1 = Serializer::serialize(ptr1);
    uintptr_t ser2 = Serializer::serialize(ptr2);
    uintptr_t ser3 = Serializer::serialize(ptr3);

    Data* deser1 = Serializer::deserialize(ser1);
    Data* deser2 = Serializer::deserialize(ser2);
    Data* deser3 = Serializer::deserialize(ser3);

    bool allMatch = (ptr1 == deser1) && (ptr2 == deser2) && (ptr3 == deser3);
    
    std::cout << "Original pointers: " << ptr1 << ", " << ptr2 << ", " << ptr3 << std::endl;
    std::cout << "Deserialized:      " << deser1 << ", " << deser2 << ", " << deser3 << std::endl;
    
    if (allMatch) {
        std::cout << COLOR_GREEN << "✓ SUCCESS: All multiple objects test passed!" << COLOR_RESET << std::endl;
    } else {
        std::cout << COLOR_RED << "✗ FAILURE: Multiple objects test failed!" << COLOR_RESET << std::endl;
        return 1;
    }

    std::cout << COLOR_YELLOW << "\n=== All tests passed! ===" << COLOR_RESET << std::endl;
    return 0;
}
