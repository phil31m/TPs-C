#include <iostream>
using namespace std;

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* count;
public:
    // Constructeur
    SharedPtr(T* p = nullptr) : ptr(p), count(new int(1)) {
        cout << "Création d'un SharedPtr vers " << *ptr << endl;
        cout << "Nombre de références : " << *count << endl;
    }
    
    // Constructeur de copie
    SharedPtr(const SharedPtr<T>& other) : ptr(other.ptr), count(other.count) {
        ++(*count);
        cout << "Création d'une copie" << endl;
        cout << "Nombre de références : " << *count << endl;
    }
    
    // Destructeur
    ~SharedPtr() {
        cout << "Destruction d'un SharedPtr" << endl;
        --(*count);
        if(*count == 0) {
            delete ptr;
            delete count;
            cout << "Objet supprimé" << endl;
        } else {
            cout << "Nombre de références : " << *count << endl;
        }
    }
};

int main() {
    {
        SharedPtr<int> p(new int(10));
        {
            SharedPtr<int> p2 = p;
        } // p2 est détruit ici (références diminuées)
    } // p est détruit ici, le compteur atteint zéro et l'objet est supprimé.
    
    return 0;
}
