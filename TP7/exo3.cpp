#include <iostream>
#include <string>
using namespace std;

class Joueur {
private:
    string nom;
    int score;
public:
    Joueur(const string& n, int s) : nom(n), score(s) {
        cout << "Constructeur appelé" << endl;
    }
    
    ~Joueur() {
        cout << "Destructeur appelé" << endl;
    }
    
    void afficher() const {
        cout << "Joueur: " << nom << ", Score: " << score << endl;
    }
};

int main() {
    Joueur joueur("Alice", 100);
    joueur.afficher();
    
    return 0;
}
