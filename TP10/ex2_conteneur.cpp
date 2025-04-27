#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class Conteneur {
private:
    std::vector<T> elements;
    size_t capacite;

public:
    Conteneur(size_t cap) : capacite(cap) {}

    void ajouter(const T& element) {
        if (elements.size() < capacite) {
            elements.push_back(element);
        }
    }

    T obtenir(size_t index) const {
        if (index < elements.size()) {
            return elements[index];
        }
        throw std::out_of_range("Index hors limites");
    }
};

// Spécialisation pour les pointeurs
template<typename T>
class Conteneur<T*> {
private:
    std::vector<T*> elements;
    size_t capacite;

public:
    Conteneur(size_t cap) : capacite(cap) {}

    void ajouter(T* element) {
        if (elements.size() < capacite) {
            elements.push_back(element);
        }
    }

    T* obtenir(size_t index) const {
        if (index < elements.size()) {
            return elements[index];
        }
        throw std::out_of_range("Index hors limites");
    }

    ~Conteneur() {
        for (auto ptr : elements) {
            delete ptr;
        }
    }
};

int main() {
    std::cout << "Exercise 2 - Conteneur:" << std::endl;
    
    // Test avec des entiers
    Conteneur<int> c1(3);
    c1.ajouter(10);
    c1.ajouter(20);
    c1.ajouter(30);
    c1.ajouter(40);
    std::cout << c1.obtenir(0) << " " << c1.obtenir(1) << std::endl;

    // Test avec des chaînes
    Conteneur<std::string> c2(2);
    c2.ajouter("Bonjour");
    c2.ajouter("Monde");
    std::cout << c2.obtenir(0) << " " << c2.obtenir(1) << std::endl;

    // Test avec des pointeurs
    Conteneur<int*> c3(2);
    c3.ajouter(new int(100));
    c3.ajouter(new int(200));
    std::cout << *c3.obtenir(0) << " " << *c3.obtenir(1) << std::endl;

    return 0;
} 