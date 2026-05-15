#pragma once
#include <vector>
#include <string>

using namespace std;

struct Movie {
    string title;
    int year;
    double rating;
    int duration;
};

vector<Movie>& getMovies();
void addMovie(const Movie& movie);
