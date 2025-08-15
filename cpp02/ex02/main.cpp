#include <iostream>
#include "Fixed.hpp"
int main( void ) 
{
Fixed a(300);
Fixed b(2);
std::cout << a << std::endl;
std::cout << a / b << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;


return 0;
}