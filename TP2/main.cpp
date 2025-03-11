#include <iostream>
#include <string>

#define EXERCISE 1

#if EXERCISE == 1
#include <iostream>
#define PI 3.14159

#ifdef DEBUG
#define DEBUG_MSG "Debug mode is ON"
#endif

int main() {
    #ifdef DEBUG
    std::cout << DEBUG_MSG << std::endl;
    #endif
    std::cout << "PI value: " << PI << std::endl;
    return 0;
}

#elif EXERCISE == 2
#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}

#elif EXERCISE == 3
#include <iostream>

namespace custom {
    int variable = 42;
}

int main() {
    std::cout << "Using std::cout: " << custom::variable << std::endl;
    using namespace std;
    cout << "Using cout: " << custom::variable << endl;
    return 0;
}

#elif EXERCISE == 4
#include <iostream>

int main() {
    int entier;
    double decimal;

    std::cout << "Entrez un entier: ";
    std::cin >> entier;
    std::cout << "Entrez un nombre décimal: ";
    std::cin >> decimal;

    std::cout << "Valeurs saisies: " << entier << " et " << decimal << std::endl;
    return 0;
}

#endif