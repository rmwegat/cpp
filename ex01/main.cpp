#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        RPN calculator;
        double result = calculator.calculate(argv[1]);
        
        // Display result as integer if it's a whole number
        if (result == static_cast<int>(result)) {
            std::cout << static_cast<int>(result) << std::endl;
        } else {
            std::cout << result << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}

// Test cases:
// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// $> ./RPN "7 7 * 7 -"
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// $> ./RPN "(1 + 1)"
// Error


// echo "Testing edge cases:" && ./RPN "5 0 /" || echo "Division by zero handled" && ./RPN "5" || echo "Single number handled" && ./RPN "5 +" || echo "Insufficient operands handled" && ./RPN "" || echo "Empty expression handled"
// echo "More tests:" && ./RPN "3 4 +" && ./RPN "9 3 /" && ./RPN "2 3 *" && ./RPN "8 2 -"