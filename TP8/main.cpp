#include <iostream>
#include "Movies.h"

// Déclaration des fonctions
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

/******************************************************************
* increment_watched attend une référence à un objet Movies
* ainsi que le nom du film dont on veut incrémenter le compteur de visionnage.
*
* Si le compteur de visionnage a été incrémenté avec succès,
* un message de succès est affiché.
* Sinon, le compteur de visionnage n'a pas pu être incrémenté
* car le nom du film n'a pas été trouvé.
******************************************************************/
void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " visionnage incrémenté" << std::endl;
    } else {
        std::cout << name << " introuvable" << std::endl;
    }
}

/******************************************************************
* add_movie attend une référence à un objet Movies
* ainsi que le nom du film, sa classification et son nombre de visionnages.
*
* Si le film a été ajouté avec succès à l'objet Movies,
* un message de succès est affiché.
* Sinon, le film n'a pas été ajouté
* car un film portant ce nom est déjà présent dans Movies.
******************************************************************/
void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << " ajouté" << std::endl;
    } else {
        std::cout << name << " existe déjà" << std::endl;
    }
}

int main() {
    Movies my_movies;
    my_movies.display();
    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cendrillon", "PG", 7);
    my_movies.display();
    add_movie(my_movies, "Cendrillon", "PG", 7);
    add_movie(my_movies, "L'Âge de glace", "PG", 12);
    my_movies.display();
    increment_watched(my_movies, "Big");
    increment_watched(my_movies, "L'Âge de glace");
    my_movies.display();
    increment_watched(my_movies, "XXX");
    return 0;
} 