#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <cerrno>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" ||
            literal == "inf"  || literal == "inff");
}

static void handlePseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    } else {
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
}

static void printFromChar(char c) {
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    if (isPseudoLiteral(literal)) {
        handlePseudoLiteral(literal);
        return;
    }

    // Single character literal (e.g. 'c' or c without quotes if single non-digit character)
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        printFromChar(literal[0]);
        return;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        printFromChar(literal[1]);
        return;
    }

    // Numeric conversion
    char* endptr = NULL;
    errno = 0;
    double d = std::strtod(literal.c_str(), &endptr);

    if (endptr == literal.c_str()) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Check remainder: must be either empty or just 'f' / 'F'
    if (*endptr != '\0') {
        if (!((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0')) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    }

    // 1. char conversion
    if (d < 0 || d > 127 || d != d) {
        std::cout << "char: impossible\n";
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c))) {
            std::cout << "char: '" << c << "'\n";
        } else {
            std::cout << "char: Non displayable\n";
        }
    }

    // 2. int conversion
    if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
        d > static_cast<double>(std::numeric_limits<int>::max()) ||
        d != d) {
        std::cout << "int: impossible\n";
    } else {
        int i = static_cast<int>(d);
        std::cout << "int: " << i << "\n";
    }

    // 3. float conversion
    float f = static_cast<float>(d);
    if (d != d) {
        std::cout << "float: nanf\n";
    } else if (f == std::numeric_limits<float>::infinity()) {
        std::cout << "float: +inff\n";
    } else if (f == -std::numeric_limits<float>::infinity()) {
        std::cout << "float: -inff\n";
    } else {
        if (std::floor(d) == d && d < 1e6 && d > -1e6) {
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        } else {
            std::cout << "float: " << f << "f\n";
        }
    }

    // 4. double conversion
    if (d != d) {
        std::cout << "double: nan\n";
    } else if (d == std::numeric_limits<double>::infinity()) {
        std::cout << "double: +inf\n";
    } else if (d == -std::numeric_limits<double>::infinity()) {
        std::cout << "double: -inf\n";
    } else {
        if (std::floor(d) == d && d < 1e6 && d > -1e6) {
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
        } else {
            std::cout << "double: " << d << "\n";
        }
    }
}
