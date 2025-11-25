#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // target is const, so it can't be reassigned
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return target;
}

// Override the pure virtual function
void ShrubberyCreationForm::executeAction() const {
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not create shrubbery file");
    }

    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    file << "\n";
    file << "      /^^\\/^^\\\n";
    file << "     /  ^  ^  \\\n";
    file << "    /  /_\\/_\\  \\\n";  
    file << "   /   \\_/\\_/   \\\n";
    file << "  /    }|{      \\\n";
    file << " /     }|{       \\\n";
    file << "/______}|{________\\\n";
    file << "       }|{\n";
    file << "       }|{\n";
    file << "\n";
    file << "        /\\\\\n";
    file << "       /  \\\\\n";
    file << "      /____\\\\\n";
    file << "     /      \\\\\n";
    file << "    /        \\\\\n";
    file << "   /__________\\\\\n";
    file << "       ||||\n";
    file << "       ||||\n";

    file.close();
    std::cout << "Shrubbery has been planted at " << target << std::endl;
}
