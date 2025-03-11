#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>

#ifndef EXERCICE
#define EXERCISE 1 // Macro pour sélectionner l'exercice par défaut
#endif

#if EXERCISE == 1
/* Exercice 1: Manipulation d'un tableau C 1D */
int main() {
    int tab[5] = {10, 20, 30, 40, 50};
    int somme = 0;
    
    // Affichage des éléments et calcul de la somme
    std::cout << "Éléments : ";
    for (auto& el : tab) {
        std::cout << el << " ";
        somme += el;
    }
    std::cout << "\nSomme : " << somme << "\n";
    return 0;
}

#elif EXERCISE == 2
/* Exercice 2: Matrice 3x3 et somme diagonale */
int main() {
    int matrice[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int diag = 0;
    
    // Affichage de la matrice et calcul de la diagonale
    std::cout << "Matrice :\n";
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j)
            std::cout << matrice[i][j] << " ";
        std::cout << "\n";
        diag += matrice[i][i]; // Addition des éléments diagonaux
    }
    std::cout << "Somme diagonale : " << diag << "\n";
    return 0;
}

#elif EXERCISE == 3
/* Exercice 3: Inversion d'un std::array */
int main() {
    std::array<int,5> arr = {1,2,3,4,5};
    std::cout << "Original : ";
    for (auto& el : arr) std::cout << el << " ";
    
    std::reverse(arr.begin(), arr.end()); // Inversion du tableau
    
    std::cout << "\nInversé : ";
    for (auto& el : arr) std::cout << el << " ";
    return 0;
}

#elif EXERCISE == 4
/* Exercice 4: Doubler les éléments d'un vecteur */
int main() {
    std::vector<int> vec;
    int n;
    
    // Lecture des entrées utilisateur
    std::cout << "Entrez des nombres (Ctrl+D pour terminer): ";
    while (std::cin >> n) vec.push_back(n);
    
    // Modification en place : chaque élément x2
    for (auto& el : vec) el *= 2;
    
    std::cout << "Doublé : ";
    for (auto& el : vec) std::cout << el << " ";
    return 0;
}

#elif EXERCISE == 5
/* Exercice 5: Insertion dans une std::list */
int main() {
    std::list<int> lst = {10,20,30,40,50};
    lst.push_front(0);   // Insertion au début
    lst.push_back(60);   // Insertion à la fin
    
    std::cout << "Après insertion : ";
    for (auto& el : lst) std::cout << el << " ";
    return 0;
}

#elif EXERCISE == 6
/* Exercice 6: Gestion des doublons avec std::set */
int main() {
    std::set<int> s = {5,10,15,20};
    s.insert(10); // L'insertion de 10 est ignorée (déjà présent)
    
    std::cout << "Après insertion de 10 : ";
    for (auto& el : s) std::cout << el << " ";
    return 0;
}

#elif EXERCISE == 7
/* Exercice 7: Stockage clé-valeur avec std::map */
int main() {
    std::map<std::string, int> notes = {{"John",85}, {"Alice",90}, {"Bob",78}};
    
    // Affichage avec structured bindings (C++17)
    for (const auto& [nom, note] : notes)
        std::cout << nom << " : " << note << "\n";
    return 0;
}

#elif EXERCISE == 8
/* Exercice 8: Compteur de mots avec unordered_map */
int main() {
    std::unordered_map<std::string, int> compteur;
    std::string phrase, mot;
    
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, phrase);
    std::istringstream iss(phrase); // Découpage de la phrase
    
    while (iss >> mot) compteur[mot]++; // Incrémentation du compteur
    
    for (const auto& [m, c] : compteur)
        std::cout << m << " : " << c << "\n";
    return 0;
}

#elif EXERCISE == 9
/* Exercice 9: Tri d'un vecteur avec std::sort */
int main() {
    std::vector<int> vec = {30,10,50,20,40};
    std::cout << "Original : ";
    for (auto& el : vec) std::cout << el << " ";
    
    std::sort(vec.begin(), vec.end()); // Tri en O(n log n)
    
    std::cout << "\nTrié : ";
    for (auto& el : vec) std::cout << el << " ";
    return 0;
}

#elif EXERCISE == 10
/* Exercice 10: Plus longue séquence consécutive */
int main() {
    std::set<int> s = {100,4,200,1,3,2};
    int max_seq = 0, current_seq = 0, last = -1;
    
    // Parcours ordonné du set (éléments triés)
    for (auto el : s) {
        if (el == last +1) current_seq++;
        else current_seq = 1;
        max_seq = std::max(max_seq, current_seq);
        last = el;
    }
    std::cout << "Plus longue séquence : " << max_seq << "\n";
    return 0;
}

#elif EXERCISE == 11
/* Exercice 11: Implémentation d'un cache LRU */
#include <unordered_map>
#include <list>
class LRUCache {
    int capacity;
    std::list<std::pair<int, int>> lru; // Stocke les paires (clé, valeur)
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // Accès rapide
    
public:
    LRUCache(int cap) : capacity(cap) {}
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        // Déplace l'élément en tête (récemment utilisé)
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            // Mise à jour et déplacement en tête
            lru.splice(lru.begin(), lru, cache[key]);
            cache[key]->second = value;
            return;
        }
        if (cache.size() >= capacity) {
            // Supprime le moins récent (dernier élément)
            auto last = lru.back().first;
            lru.pop_back();
            cache.erase(last);
        }
        lru.emplace_front(key, value); // Ajoute en tête
        cache[key] = lru.begin();
    }
    
    void display() {
        for (const auto& p : lru)
            std::cout << "(" << p.first << "," << p.second << ") ";
        std::cout << "\n";
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1,10);
    cache.put(2,20);
    cache.get(1);      // 1 devient récent
    cache.put(3,30);   // 2 est supprimé (capacity=2)
    cache.display();   // Affiche (3,30) (1,10)
    return 0;
}

#else
int main() {
    std::cout << "Exercice non défini!\n";
    return 0;
}
#endif