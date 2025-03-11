#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Objet {
public:
    string nom;
    int quantite;
    
    Objet(const string& n, int q) : nom(n), quantite(q) {}
};

class Inventaire {
private:
    vector<Objet*> objets;
public:
    ~Inventaire() {
        for(auto obj : objets) {
            delete obj;
        }
        cout << "Mémoire de l'inventaire libérée." << endl;
    }
    
    void ajouterObjet(const string& nom, int quantite) {
        Objet* obj = new Objet(nom, quantite);
        objets.push_back(obj);
        cout << "Ajout de " << nom << " (x" << quantite << ")" << endl;
    }
    
    void afficher() const {
        cout << "Inventaire :" << endl;
        for(auto obj : objets) {
            cout << "- " << obj->nom << " (x" << obj->quantite << ")" << endl;
        }
    }
};

int main() {
    Inventaire inv;
    inv.ajouterObjet("Pomme", 3);
    inv.ajouterObjet("Épée", 1);
    
    inv.afficher();
    
    return 0;
}
