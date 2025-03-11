// Exercice 5
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void sort_by_length(const string& text) {
    multimap<int, string> word_map;
    istringstream iss(text);
    string word;
    
    while (iss >> word) {
        word_map.insert(make_pair(word.length(), word));
    }
    
    cout << "Trie par longueur : ";
    for (const auto& pair : word_map) {
        cout << pair.second << " ";
    }
    cout << endl;
}

// Exemple d'utilisation :
// sort_by_length("Le langage C++ est rapide et efficace");