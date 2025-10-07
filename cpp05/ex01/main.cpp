#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define COLOR_RESET   "\033[0m"
#define COLOR_YELLOW  "\033[33m"

int main() {
    std::cout << COLOR_YELLOW << "=== Form Testing ===" << COLOR_RESET << std::endl;

    try {
        std::cout << COLOR_YELLOW << "\n1. Creating valid forms:" << COLOR_RESET << std::endl;
        Form form1("Tax Form", 50, 25);
        Form form2("Permit Application", 100, 75);
        
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        std::cout << COLOR_YELLOW << "\n2. Creating bureaucrats:" << COLOR_RESET << std::endl;
        Bureaucrat alice("Alice", 30);
        Bureaucrat bob("Bob", 60);
        Bureaucrat charlie("Charlie", 120);
        
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        std::cout << COLOR_YELLOW << "\n3. Successful form signing:" << COLOR_RESET << std::endl;
        alice.signForm(form1);
        bob.signForm(form2);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        std::cout << COLOR_YELLOW << "\n4. Failed form signing (grade too low):" << COLOR_RESET << std::endl;
        charlie.signForm(form1);

        std::cout << COLOR_YELLOW << "\n5. Try to sign already signed form:" << COLOR_RESET << std::endl;
        alice.signForm(form1);

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << COLOR_YELLOW << "\n6. Creating form with invalid grades:" << COLOR_RESET << std::endl;
        Form invalidForm1("Invalid High", 0, 50);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid Low", 50, 151);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << COLOR_YELLOW << "\n7. Testing copy constructor and assignment:" << COLOR_RESET << std::endl;
    Form original("Original", 75, 50);
    Form copied(original);
    Form assigned("Temp", 100, 100);
    assigned = original;

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copied: " << copied << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    return 0;
}