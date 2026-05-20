#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat yunus("Yunus", 2);
        Bureaucrat esra("Esra", 149);
        std::cout << yunus << std::endl;
        yunus.incrementGrade();
        std::cout << yunus << std::endl;
        std::cout << esra << std::endl;
        esra.decrementGrade();
        std::cout << esra << std::endl;
        yunus.incrementGrade();
        esra.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
