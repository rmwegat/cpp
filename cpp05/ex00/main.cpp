#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        b1.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << "After decrement: " << b2 << std::endl;
        b2.decrementGrade();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Diana", 0);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	return 0;
}