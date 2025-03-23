#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watched;

public:
    // Getters
    std::string get_name() const;
    std::string get_rating() const;
    int get_watched() const;

    // Setters
    void set_name(std::string name);
    void set_rating(std::string rating);
    void set_watched(int watched);

    // Other methods
    void increment_watched();
    void display() const;
};

#endif // MOVIE_H 