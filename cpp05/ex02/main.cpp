#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Bureaucrat president("President", 1);
    Bureaucrat manager("Manager", 45);
    Bureaucrat intern("Intern", 140);
    Bureaucrat rookie("Rookie", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "--- Test 1: Unsigned execution failure ---" << std::endl;
    president.executeForm(shrub);

    std::cout << "\n--- Test 2: Low grade signing failure ---" << std::endl;
    rookie.signForm(shrub);

    std::cout << "\n--- Test 3: ShrubberyCreationForm (Sign 145, Exec 137) ---" << std::endl;
    intern.signForm(shrub);
    rookie.executeForm(shrub); // Exec grade too low
    intern.executeForm(shrub);  // Exec grade 140 > 137 failure
    manager.executeForm(shrub); // Success

    std::cout << "\n--- Test 4: RobotomyRequestForm (Sign 72, Exec 45) ---" << std::endl;
    manager.signForm(robo);
    manager.executeForm(robo);
    manager.executeForm(robo);

    std::cout << "\n--- Test 5: PresidentialPardonForm (Sign 25, Exec 5) ---" << std::endl;
    president.signForm(pardon);
    manager.executeForm(pardon); // Exec grade 45 > 5 failure
    president.executeForm(pardon); // Success

    return 0;
}
