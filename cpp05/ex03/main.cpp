#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    std::cout << "--- Test 1: Subject example (robotomy request) ---" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Test 2: Shrubbery creation form ---" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Test 3: Presidential pardon form ---" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Test 4: Unknown form request ---" << std::endl;
    form = someRandomIntern.makeForm("coffee request", "Boss");
    if (form) {
        delete form;
    }

    return 0;
}
