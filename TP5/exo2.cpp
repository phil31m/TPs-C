// Exercice 2
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <string>

void word_frequency(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::vector<std::string> order;
    std::istringstream iss(text);
    std::string word;
    
    while (iss >> word) {
        if (freq.find(word) == freq.end()) {
            order.push_back(word);
        }
        ++freq[word];
    }
    
    std::cout << "Fréquence des mots :" << std::endl;
    for (const auto& w : order) {
        std::cout << w << " -> " << freq[w] << std::endl;
    }
}

// Example usage:
int main() {
    std::string input;
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, input);
    word_frequency(input);
    return 0;
}