#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    outfile << "      /\\      " << std::endl;
    outfile << "     /  \\     " << std::endl;
    outfile << "    /    \\    " << std::endl;
    outfile << "   /  /\\  \\   " << std::endl;
    outfile << "  /  /  \\  \\  " << std::endl;
    outfile << " /__/    \\__\\ " << std::endl;
    outfile << "    ||  ||    " << std::endl;
    outfile << "    ||  ||    " << std::endl;
    outfile << std::endl;
    outfile << "      /\\      " << std::endl;
    outfile << "     /  \\     " << std::endl;
    outfile << "    /    \\    " << std::endl;
    outfile << "   /  /\\  \\   " << std::endl;
    outfile << "  /  /  \\  \\  " << std::endl;
    outfile << " /__/    \\__\\ " << std::endl;
    outfile << "    ||  ||    " << std::endl;
    outfile << "    ||  ||    " << std::endl;

    outfile.close();
}
