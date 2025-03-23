#include "Movies.h"
#include <iostream>

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // Check if movie already exists
    for (const auto& movie : movies) {
        if (movie.get_name() == name) {
            return false;
        }
    }
    
    // Create and add new movie
    Movie movie;
    movie.set_name(name);
    movie.set_rating(rating);
    movie.set_watched(watched);
    movies.push_back(movie);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto& movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movies.empty()) {
        std::cout << "Désolé, aucun film à afficher" << std::endl;
        return;
    }
    
    std::cout << "===================================" << std::endl;
    for (const auto& movie : movies) {
        movie.display();
        std::cout << std::endl;
    }
    std::cout << "===================================" << std::endl;
} 