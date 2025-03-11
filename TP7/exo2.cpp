#include <iostream>
#include <string>
using namespace std;


class Joueur {
private:
    string nom;
    int score;
public:
    Joueur(const string& n, int s) : nom(n), score(s) {}
    
    void afficher() const {
        cout << "Nom: " << nom << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Joueur* joueur = new Joueur("Alice", 100);
    joueur->afficher();
    
    delete joueur;
    cout << "Objet dynamique supprimé." << endl;
    
    return 0;
}
