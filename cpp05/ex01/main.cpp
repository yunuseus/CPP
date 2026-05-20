#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(){
    try
    {
        Bureaucrat yunus("Yunus", 3);
        Form form("Form1", 3, 2);
        std::cout << yunus << std::endl;
        std::cout << form << std::endl;
        form.beSigned(yunus);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
