#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& rhs);
    ~Intern();

    AForm* makeForm(std::string const & formName, std::string const & target);
};

#endif
