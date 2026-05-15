#include "logic.h"

void addMovieLogic(string title, int year, double rating, int duration) {
    Movie m;
    m.title = title;
    m.year = year;
    m.rating = rating;
    m.duration = duration;

    addMovie(m);
}

void sortByTitle() {
    vector<Movie>& movies = getMovies();

    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies.size() - 1; j++) {
            if (movies[j].title > movies[j + 1].title) {
                swap(movies[j], movies[j + 1]);
            }
        }
    }
}

void sortByYear() {
    vector<Movie>& movies = getMovies();

    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies.size() - 1; j++) {
            if (movies[j].year > movies[j + 1].year) {
                swap(movies[j], movies[j + 1]);
            }
        }
    }
}

void sortByRating() {
    vector<Movie>& movies = getMovies();

    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies.size() - 1; j++) {
            if (movies[j].rating > movies[j + 1].rating) {
                swap(movies[j], movies[j + 1]);
            }
        }
    }
}

int searchByTitle(string title) {
    vector<Movie>& movies = getMovies();

    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].title == title) {
            return i;
        }
    }

    return -1;
}

int totalDurationRecursive(int index) {
    vector<Movie>& movies = getMovies();

    if (index >= movies.size()) {
        return 0;
    }

    return movies[index].duration + totalDurationRecursive(index + 1);
}