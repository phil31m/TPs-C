#include <iostream>
#include <memory>
#include <vector>
#include <string>

class PaireBase {
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const = 0;
};

template<typename T1, typename T2>
class Paire : public PaireBase {
private:
    T1 premier;
    T2 second;

public:
    Paire(const T1& p, const T2& s) : premier(p), second(s) {}

    void afficher() const override {
        std::cout << "(" << premier << ", " << second << ")" << std::endl;
    }
};

// Spécialisation pour les paires de même type
template<typename T>
class Paire<T, T> : public PaireBase {
private:
    T premier;
    T second;

public:
    Paire(const T& p, const T& s) : premier(p), second(s) {}

    void afficher() const override {
        std::cout << "Paire de même type: (" << premier << ", " << second << ")" << std::endl;
    }

    T somme() const {
        return premier + second;
    }
};

int main() {
    std::cout << "Exercise 3 - Paire:" << std::endl;
    std::vector<std::unique_ptr<PaireBase>> paires;
    
    // Paires de types différents
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));
    
    // Paires de même type
    paires.push_back(std::make_unique<Paire<int, int>>(5, 10));
    paires.push_back(std::make_unique<Paire<double, double>>(1.5, 2.5));

    for (const auto& p : paires) {
        p->afficher();
        // Si c'est une paire de même type, on peut faire la somme
        if (auto paireMemeType = dynamic_cast<const Paire<int, int>*>(p.get())) {
            std::cout << "Somme: " << paireMemeType->somme() << std::endl;
        }
    }
    return 0;
} 