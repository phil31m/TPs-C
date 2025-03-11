#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Fichier {
private:
    string nom;
public:
    Fichier(const string& n) : nom(n) {}
    
    void sauvegarder(const string& contenu) {
        cout << "Sauvegarde des données..." << endl;
        ofstream* ofs = new ofstream(nom);
        if (ofs->is_open()) {
            (*ofs) << contenu;
            ofs->close();
        }
        delete ofs;
    }
    
    void lire() {
        cout << "Lecture des données..." << endl;
        ifstream* ifs = new ifstream(nom);
        if (ifs->is_open()) {
            string ligne;
            cout << "Contenu du fichier :" << endl;
            while(getline(*ifs, ligne)) {
                cout << ligne << endl;
            }
            ifs->close();
        }
        delete ifs;
    }
};

int main() {
    Fichier f("test.txt");
    f.sauvegarder("Bonjour, ceci est un test.");
    f.lire();
    cout << "Mémoire du flux libérée." << endl;
    
    return 0;
}
