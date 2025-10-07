#include "ScalarConverter.hpp"
#include <iostream>

/*
 * ScalarConverter Test Examples:
 * 
 * Character literals:
 *   ./convert 'a'    - converts character 'a'
 *   ./convert 'Z'    - converts character 'Z'
 *   ./convert '0'    - converts character '0' (ASCII 48)
 * 
 * Integer literals:
 *   ./convert 0      - converts integer 0
 *   ./convert 42     - converts positive integer
 *   ./convert -42    - converts negative integer
 *   ./convert 127    - converts max char value
 *   ./convert 2147483647  - converts max int value
 * 
 * Float literals:
 *   ./convert 0.0f   - converts float zero
 *   ./convert 42.0f  - converts float with .0
 *   ./convert -4.2f  - converts negative float
 *   ./convert 3.14f  - converts pi as float
 *   ./convert nanf   - converts float NaN
 *   ./convert +inff  - converts positive infinity
 *   ./convert -inff  - converts negative infinity
 * 
 * Double literals:
 *   ./convert 0.0    - converts double zero
 *   ./convert 42.42  - converts decimal double
 *   ./convert -4.2   - converts negative double
 *   ./convert nan    - converts double NaN
 *   ./convert +inf   - converts positive infinity
 *   ./convert -inf   - converts negative infinity
 */

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cout << "Examples:" << std::endl;
        std::cout << "  " << argv[0] << " 0" << std::endl;
        std::cout << "  " << argv[0] << " nan" << std::endl;
        std::cout << "  " << argv[0] << " 42.0f" << std::endl;
        std::cout << "  " << argv[0] << " 'c'" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}