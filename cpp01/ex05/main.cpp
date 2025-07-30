#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "=== DEBUG ===" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "=== INFO ===" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "=== WARNING ===" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "=== ERROR ===" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "=== INVALID ===" << std::endl;
    harl.complain("INVALID");
    
    return 0;
}