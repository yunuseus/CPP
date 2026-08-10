#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- Test 1: Valid Form Creation ---" << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Form Invalid Grade ---" << std::endl;
    try {
        Form f2("Invalid Form", 0, 50);
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Bureaucrat Signing Form (Success & Failure) ---" << std::endl;
    try {
        Bureaucrat yunus("yunus", 10);
        Bureaucrat emre("emre", 100);

        Form topSecret("Top Secret", 20, 10);

        std::cout << topSecret << std::endl;
        std::cout << emre << std::endl;
        std::cout << yunus << std::endl;

        emre.signForm(topSecret);
        std::cout << topSecret << std::endl;

        yunus.signForm(topSecret);
        std::cout << topSecret << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
