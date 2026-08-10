#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Test 1: Valid Bureaucrats ---" << std::endl;
    try {
        Bureaucrat yunus("yunus", 1);
        std::cout << yunus << std::endl;
        Bureaucrat emre("emre", 150);
        std::cout << emre << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too High at Construction ---" << std::endl;
    try {
        Bureaucrat high("high", 0);
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade Too Low at Construction ---" << std::endl;
    try {
        Bureaucrat low("low", 151);
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Increment Grade Boundary ---" << std::endl;
    try {
        Bureaucrat esra("esra", 2);
        std::cout << esra << std::endl;
        esra.incrementGrade();
        std::cout << "After increment: " << esra << std::endl;
        std::cout << "Attempting to increment grade 1..." << std::endl;
        esra.incrementGrade();
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Decrement Grade Boundary ---" << std::endl;
    try {
        Bureaucrat alp("alp", 149);
        std::cout << alp << std::endl;
        alp.decrementGrade();
        std::cout << "After decrement: " << alp << std::endl;
        std::cout << "Attempting to decrement grade 150..." << std::endl;
        alp.decrementGrade();
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}
