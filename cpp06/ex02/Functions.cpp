#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

Base* generate(void) {
    // Use modern C++ random number generation
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);
    
    int random = dist(gen);
    
    switch (random) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C";
    } else {
        std::cout << "Unknown";
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Suppress unused variable warning
        std::cout << "A";
        return;
    } catch (const std::bad_cast&) {
        // Not type A, continue
    }
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b; // Suppress unused variable warning
        std::cout << "B";
        return;
    } catch (const std::bad_cast&) {
        // Not type B, continue
    }
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c; // Suppress unused variable warning
        std::cout << "C";
        return;
    } catch (const std::bad_cast&) {
        // Not type C
        std::cout << "Unknown";
    }
}