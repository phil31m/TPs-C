#include <iostream>
#include <stdexcept>

class DivideByZeroException : public std::runtime_error {
public:
    DivideByZeroException() : std::runtime_error("Division by zero is not allowed") {}
};

class InvalidOperationException : public std::runtime_error {
public:
    InvalidOperationException() : std::runtime_error("Invalid operation") {}
};

// Template général pour les types numériques
template<typename T>
T calculate(T num1, T num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                throw DivideByZeroException();
            }
            return num1 / num2;
        default:
            throw InvalidOperationException();
    }
}

// Spécialisation pour les entiers (division entière)
template<>
int calculate<int>(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                throw DivideByZeroException();
            }
            return num1 / num2; // Division entière pour les int
        default:
            throw InvalidOperationException();
    }
}

// Spécialisation pour les doubles (division flottante)
template<>
double calculate<double>(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                throw DivideByZeroException();
            }
            return num1 / num2; // Division flottante pour les double
        default:
            throw InvalidOperationException();
    }
}

int main() {
    // Test avec des entiers
    try {
        int result_int = calculate<int>(10, 3, '/');
        std::cout << "Result (int): " << result_int << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    // Test avec des doubles
    try {
        double result_double = calculate<double>(10.0, 3.0, '/');
        std::cout << "Result (double): " << result_double << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}