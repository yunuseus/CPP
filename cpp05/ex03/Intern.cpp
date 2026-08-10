#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(std::string const & target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const & target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string const & target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const & formName, std::string const & target) {
    typedef AForm* (*FormCreator)(std::string const & target);

    static const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    static const FormCreator creators[3] = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            AForm* form = creators[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cerr << "Error: Intern cannot create '" << formName 
              << "' because form name is unrecognized." << std::endl;
    return NULL;
}
