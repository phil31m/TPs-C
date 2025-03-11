#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Etudiant {
private:
    string nom;
    vector<int> notes;
public:
    Etudiant(const string& n, const vector<int>& nt) : nom(n), notes(nt) {}
    
    double moyenne() const {
        double somme = 0;
        for (int note : notes) {
            somme += note;
        }
        return (notes.empty() ? 0 : somme / notes.size());
    }
    
    void afficher() const {
        cout << "Nom: " << nom << endl;
        cout << "Notes: ";
        for (size_t i = 0; i < notes.size(); ++i) {
            cout << notes[i];
            if(i < notes.size()-1) cout << ", ";
        }
        cout << endl;
        cout << "Moyenne: " << fixed << setprecision(1) << moyenne() << endl;
    }
};

int main() {
    Etudiant etu("Karim", {15, 18, 12});
    etu.afficher();
    
    return 0;
}
