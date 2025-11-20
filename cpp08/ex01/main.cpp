#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== Span Class Tests ===" << std::endl;
    
    try {
        // Test 1: Basic functionality (provided example)
        std::cout << "\n1. Testing basic functionality:" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Numbers: 6, 3, 17, 9, 11" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << " (expected: 2)" << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << " (expected: 14)" << std::endl;
        
        // Test 2: Exception handling
        std::cout << "\n2. Testing exceptions:" << std::endl;
        try {
            Span fullSpan(2);
            fullSpan.addNumber(1);
            fullSpan.addNumber(2);
            fullSpan.addNumber(3);  // Should throw
        } catch (const std::exception& e) {
            std::cout << "Full span exception: " << e.what() << std::endl;
        }
        
        try {
            Span emptySpan(5);
            emptySpan.shortestSpan();  // Should throw
        } catch (const std::exception& e) {
            std::cout << "Empty span exception: " << e.what() << std::endl;
        }
        
        // Test 3: Iterator range (addNumbers)
        std::cout << "\n3. Testing iterator range:" << std::endl;
        Span rangeSpan(10);
        std::vector<int> numbers;
        for (int i = 0; i < 8; ++i) {
            numbers.push_back(i * 10);
        }
        rangeSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Added " << rangeSpan.size() << " numbers using iterators" << std::endl;
        std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
        
        // Test 4: Large numbers (10,000+)
        std::cout << "\n4. Testing with 10,000 numbers:" << std::endl;
        const unsigned int LARGE_SIZE = 10000;
        Span largeSpan(LARGE_SIZE);
        
        std::vector<int> largeNumbers;
        for (unsigned int i = 0; i < LARGE_SIZE; ++i) {
            largeNumbers.push_back(static_cast<int>(i * 2));
        }
        
        largeSpan.addNumbers(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Successfully added " << largeSpan.size() << " numbers" << std::endl;
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
        
        std::cout << "\n=== All tests completed successfully! ===" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

