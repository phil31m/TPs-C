#include "Movie.h"
#include <iostream>

// Getters
std::string Movie::get_name() const {
    return name;
}

std::string Movie::get_rating() const {
    return rating;
}

int Movie::get_watched() const {
    return watched;
}

// Setters
void Movie::set_name(std::string name) {
    this->name = name;
}

void Movie::set_rating(std::string rating) {
    this->rating = rating;
}

void Movie::set_watched(int watched) {
    this->watched = watched;
}

// Other methods
void Movie::increment_watched() {
    watched++;
}

void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched;
} 