#include <iostream>
#include <string>
#include <filesystem>
#include "whatever.hpp"

int main( void ) {
    std::cout << "=== Testing with integers ===" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
    std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
    
    std::cout << "\n=== Testing with strings ===" << std::endl;
    std::string c = "string 1";
    std::string d = "string 2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
    std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
    
    return 0;
}