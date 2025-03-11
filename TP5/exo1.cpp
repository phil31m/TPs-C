// Exercice-1
#include <algorithm>
#include <cctype>
#include <string>

bool is_palindrome(const std::string& text) {
    std::string filtered;
    for (char c : text) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            filtered.push_back(std::tolower(static_cast<unsigned char>(c)));
        }
    }
    std::string reversed = filtered;
    std::reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}