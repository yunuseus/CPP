#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "===== Exercise 02: Identify Real Type =====" << std::endl;

    std::cout << "\n--- Testing with randomly generated instances ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "\n[Test " << i + 1 << "]" << std::endl;
        Base* instance = generate();
        
        std::cout << "Identify via pointer:   ";
        identify(instance);

        std::cout << "Identify via reference: ";
        identify(*instance);

        delete instance;
    }

    std::cout << "\n--- Testing direct known instances ---" << std::endl;
    A a;
    B b;
    C c;

    std::cout << "\nInstance of A:" << std::endl;
    std::cout << "Pointer:   "; identify(&a);
    std::cout << "Reference: "; identify(a);

    std::cout << "\nInstance of B:" << std::endl;
    std::cout << "Pointer:   "; identify(&b);
    std::cout << "Reference: "; identify(b);

    std::cout << "\nInstance of C:" << std::endl;
    std::cout << "Pointer:   "; identify(&c);
    std::cout << "Reference: "; identify(c);

    std::cout << "\n--- Testing NULL pointer ---" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Pointer:   "; identify(nullPtr);

    return 0;
}
