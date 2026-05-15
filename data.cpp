#include "data.h"
#include <vector>

using namespace std;

static vector<Movie> movies;

vector<Movie>& getMovies() {
    return movies;
}

void addMovie(const Movie& movie) {
    movies.push_back(movie);
}