#include <iostream>
#include <string>

template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Spécialisation pour std::string
template<>
std::string maximum<std::string>(std::string a, std::string b) {
    return (a.length() > b.length()) ? a : b;
}

int main() {
    std::cout << "Exercise 1 - maximum:" << std::endl;
    std::cout << maximum(5, 10) << std::endl;
    std::cout << maximum(3.14, 2.71) << std::endl;
    std::cout << maximum(std::string("chat"), std::string("chien")) << std::endl;
    return 0;
} 