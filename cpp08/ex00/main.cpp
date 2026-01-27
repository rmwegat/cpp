#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <exception>
#include "easyfind.hpp"

int main() {
    std::cout << "=== Testing easyfind function template ===" << std::endl;
    
    try {
        std::cout << "\n1. Testing with std::vector:" << std::endl;
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);
        
        std::cout << "Vector contains: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::vector<int>::iterator found = easyfind(vec, 30);
        std::cout << "Found value 30 at position: " << std::distance(vec.begin(), found) << std::endl;
        
        found = easyfind(vec, 10);
        std::cout << "Found value 10 at position: " << std::distance(vec.begin(), found) << std::endl;
        
        std::cout << "\n2. Testing with std::list:" << std::endl;
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        lst.push_back(200);
        lst.push_back(400);
        
        std::cout << "List contains: ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::list<int>::iterator lstFound = easyfind(lst, 200);
        std::cout << "Found first occurrence of 200 at position: " << std::distance(lst.begin(), lstFound) << std::endl;
        
        std::cout << "\n3. Testing with std::deque:" << std::endl;
        std::deque<int> deq;
        deq.push_back(5);
        deq.push_back(15);
        deq.push_back(25);
        deq.push_front(0);
        
        std::cout << "Deque contains: ";
        for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::deque<int>::iterator deqFound = easyfind(deq, 15);
        std::cout << "Found value 15 at position: " << std::distance(deq.begin(), deqFound) << std::endl;
        
        std::cout << "\n4. Testing with std::array:" << std::endl;
        std::array<int, 4> arr = {{7, 14, 21, 28}};
        
        std::cout << "Array contains: ";
        for (std::array<int, 4>::iterator it = arr.begin(); it != arr.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::array<int, 4>::iterator arrFound = easyfind(arr, 21);
        std::cout << "Found value 21 at position: " << std::distance(arr.begin(), arrFound) << std::endl;
        
        std::cout << "\n5. Testing with const container:" << std::endl;
        const std::vector<int> constVec(vec);
        std::cout << "Const vector contains: ";
        for (std::vector<int>::const_iterator it = constVec.begin(); it != constVec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::vector<int>::const_iterator constFound = easyfind(constVec, 40);
        std::cout << "Found value 40 in const vector at position: " << std::distance(constVec.begin(), constFound) << std::endl;
        
        std::cout << "\n6. Testing with empty container:" << std::endl;
        std::vector<int> emptyVec;
        std::cout << "Attempting to find value in empty vector..." << std::endl;
        try {
            easyfind(emptyVec, 42);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n7. Testing value not found:" << std::endl;
        std::cout << "Attempting to find value 999 in vector..." << std::endl;
        try {
            easyfind(vec, 999);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n8. Testing single element container:" << std::endl;
        std::vector<int> singleVec;
        singleVec.push_back(42);
        std::cout << "Single element vector contains: " << singleVec[0] << std::endl;
        
        std::vector<int>::iterator singleFound = easyfind(singleVec, 42);
        std::cout << "Found value 42 at position: " << std::distance(singleVec.begin(), singleFound) << std::endl;
        
        // Test not found in single element
        try {
            easyfind(singleVec, 43);
        } catch (const std::exception& e) {
            std::cout << "Value 43 not found in single element vector: " << e.what() << std::endl;
        }
        
        std::cout << "\n=== All tests completed successfully ===" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}