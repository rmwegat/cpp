#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

#define COLOR_RESET   "\033[0m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_BLUE    "\033[34m"

int main() {
    std::cout << COLOR_YELLOW << "=== Type Identification Testing ===" << COLOR_RESET << std::endl;

    std::cout << COLOR_YELLOW << "\n1. Testing generate() function:" << COLOR_RESET << std::endl;
    
    // Generate and test multiple objects
    for (int i = 0; i < 10; i++) {
        std::cout << COLOR_BLUE << "\nTest " << (i + 1) << ":" << COLOR_RESET << std::endl;
        
        Base* obj = generate();
        
        if (obj) {
            std::cout << "Identify by pointer: ";
            identify(obj);
            std::cout << std::endl;
            
            std::cout << "Identify by reference: ";
            identify(*obj);
            std::cout << std::endl;
            
            delete obj;
        }
    }

    std::cout << COLOR_YELLOW << "\n2. Testing with known objects:" << COLOR_RESET << std::endl;
    
    // Test with explicitly created objects
    A a;
    B b;
    C c;
    
    std::cout << COLOR_BLUE << "\nObject A:" << COLOR_RESET << std::endl;
    std::cout << "Identify by pointer: ";
    identify(&a);
    std::cout << std::endl;
    std::cout << "Identify by reference: ";
    identify(a);
    std::cout << std::endl;
    
    std::cout << COLOR_BLUE << "\nObject B:" << COLOR_RESET << std::endl;
    std::cout << "Identify by pointer: ";
    identify(&b);
    std::cout << std::endl;
    std::cout << "Identify by reference: ";
    identify(b);
    std::cout << std::endl;
    
    std::cout << COLOR_BLUE << "\nObject C:" << COLOR_RESET << std::endl;
    std::cout << "Identify by pointer: ";
    identify(&c);
    std::cout << std::endl;
    std::cout << "Identify by reference: ";
    identify(c);
    std::cout << std::endl;

    std::cout << COLOR_YELLOW << "\n3. Testing polymorphic behavior:" << COLOR_RESET << std::endl;
    
    Base* polyArray[3];
    polyArray[0] = new A();
    polyArray[1] = new B();
    polyArray[2] = new C();
    
    for (int i = 0; i < 3; i++) {
        std::cout << COLOR_BLUE << "Polymorphic object " << (i + 1) << ":" << COLOR_RESET << std::endl;
        std::cout << "Identify by pointer: ";
        identify(polyArray[i]);
        std::cout << std::endl;
        std::cout << "Identify by reference: ";
        identify(*polyArray[i]);
        std::cout << std::endl;
        
        delete polyArray[i];
    }

    std::cout << COLOR_YELLOW << "\n=== All tests completed! ===" << COLOR_RESET << std::endl;
    return 0;
}
