#include <iostream>
#include <string>
using namespace std;

class Joueur {
public:
    string nom;
    int score;
    
    Joueur(const string& n, int s) : nom(n), score(s) {}
    
    void afficher() const {
        cout << "Joueur: " << nom << ", Score: " << score << endl;
    }
};

int main() {
    Joueur joueur1("Alice", 100);
    Joueur joueur2("Bob", 200);
    
    joueur1.afficher();
    joueur2.afficher();
    
    return 0;
}
