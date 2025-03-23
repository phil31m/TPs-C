#ifndef MOVIES_H
#define MOVIES_H

#include <vector>
#include "Movie.h"

class Movies {
private:
    std::vector<Movie> movies;

public:
    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    void display() const;
};

#endif // MOVIES_H 