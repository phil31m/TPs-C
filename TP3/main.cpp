#include <iostream>
#include <limits>
#include <iomanip>

// Définition de la macro pour sélectionner l'exercice
#ifndef EXERCICE
#define EXERCISE 1 // Par défaut exercice 1
#endif

#if EXERCISE == 1
/* Exercice 1: Analyse mémoire d'un tableau */
int main() {
    int tab[10] = {0,1,2,3,4,5,6,7,8,9};
    
    // Calcul des tailles avec sizeof
    std::cout << "Taille totale du tableau : " << sizeof(tab) << " octet(s)\n";
    std::cout << "Taille d'un élément : " << sizeof(tab[0]) << " octet(s)\n";
    std::cout << "Nombre d'éléments : " << sizeof(tab)/sizeof(tab[0]) << "\n";
    return 0;
}

#elif EXERCISE == 2
/* Exercice 2: Estimation nettoyage de tapis */
int main() {
    // Définition des constantes tarifaires
    const int PETITE_PIECE = 250;
    const int GRANDE_PIECE = 350;
    const double TAXE = 0.06;
    const int JOURS = 30;

    int petites, grandes;
    std::cout << "Number of small rooms: ";
    std::cin >> petites;
    std::cout << "Number of large rooms: ";
    std::cin >> grandes;

    // Calcul des coûts
    int cout = petites * PETITE_PIECE + grandes * GRANDE_PIECE;
    double tax = cout * TAXE;
    double total = cout + tax;

    // Affichage formaté
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Estimate for carpet cleaning service\n";
    std::cout << "Number of small rooms: " << petites << "\n";
    std::cout << "Number of large rooms: " << grandes << "\n";
    std::cout << "Price per small room: " << PETITE_PIECE << "dh\n";
    std::cout << "Price per large room: " << GRANDE_PIECE << "dh\n";
    std::cout << "Cost : " << cout << "dh\n";
    std::cout << "Tax: " << tax << "dh\n";
    std::cout << "=============================\n";
    std::cout << "Total estimate: " << total << "dh\n";
    std::cout << "This estimate is valid for " << JOURS << " days\n";
    return 0;
}

#elif EXERCISE == 3
/* Exercice 3: Factorielle à la compilation */
constexpr int factorielle(int n) {
    return n <= 1 ? 1 : n * factorielle(n - 1); // Version récursive
}

int main() {
    constexpr int resultat = factorielle(5); // Calcul à la compilation
    static_assert(factorielle(5) == 120, "Erreur factorielle"); // Vérification
    std::cout << "Factorielle de 5 : " << resultat << "\n";
    return 0;
}

#elif EXERCISE == 4
/* Exercice 4: Shadowing de variables */
int value = 100; // Variable globale

int main() {
    int value = 50; // Variable locale
    std::cout << "Valeur locale : " << value << "\n";
    std::cout << "Valeur globale : " << ::value << "\n"; // Opérateur de portée
    return 0;
}

#elif EXERCISE == 5
/* Exercice 5: Différents types de constantes */
const int MOIS = 12; // Constante classique
constexpr double RAYON = 7.0; // Constante compile-time
#define PI 3.14159 // Macro

int main() {
    // MOIS = 13; // Génèrerait une erreur
    double aire = PI * RAYON * RAYON; // Calcul de l'aire
    std::cout << "Nombre de mois dans une année : " << MOIS << "\n";
    std::cout << "Rayon du cercle : " << RAYON << "\n";
    std::cout << "Aire du cercle : " << aire << "\n";
    return 0;
}

#elif EXERCISE == 6
/* Exercice 6: Détection d'overflow */
int safeMultiply(int a, int b) {
    // Vérification des cas d'overflow
    if ((b > 0 && a > std::numeric_limits<int>::max() / b) || 
        (b < 0 && a < std::numeric_limits<int>::min() / b)) {
        std::cerr << "Erreur: Overflow!\n";
        return -1;
    }
    return a * b;
}

int main() {
    // Tests avec différentes valeurs
    int a = 30000, b = 1000;
    int result = safeMultiply(a, b);
    if (result != -1) std::cout << "Resultat: " << result << "\n";

    a = 300000, b = 10000;
    result = safeMultiply(a, b);
    if (result != -1) std::cout << "Resultat: " << result << "\n";
    return 0;
}

#else
int main() {
    std::cout << "Exercice non défini!\n";
    return 0;
}
#endif