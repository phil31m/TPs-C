#include <iostream>

// Définition d'un macro pour choisir l'exercice
#define EXERCICE 3  // Changez ce nombre pour choisir l'exercice 

#if EXERCICE == 1
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Bienvenue en C++!" << std::endl;
    return 0;
}

#elif EXERCICE == 2
int main() {
    int nombre;
    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;
    std::cout << "Vous avez entre: " << nombre << std::endl;
    return 0;
}

#elif EXERCICE == 3
int main() {
    double num1, num2;

    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;
    std::cout << "Entrez le deuxième nombre: ";
    std::cin >> num2;

    std::cout << "Somme: " << num1 + num2 << std::endl;
    std::cout << "Différence: " << num1 - num2 << std::endl;
    std::cout << "Produit: " << num1 * num2 << std::endl;
    if (num2 != 0) {
        std::cout << "Quotient: " << num1 / num2 << std::endl;
    } else {
        std::cout << "Quotient: Division par zéro impossible" << std::endl;
    }

    return 0;
}

#elif EXERCICE == 4
int main() {
    double celsius, fahrenheit;

    std::cout << "Entrez la temperature en Celsius: ";
    std::cin >> celsius;

    fahrenheit = (9.0 / 5.0) * celsius + 32;

    std::cout << "La temperature en Fahrenheit est: " << fahrenheit << std::endl;

    return 0;
}

#else
#error "Numero d'exercice invalide. Choisissez une valeur entre 1 et 4."
#endif
