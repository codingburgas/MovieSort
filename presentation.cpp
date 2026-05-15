#include <iostream>
#include <limits>
#include "presentation.h"
#include "logic.h"
#include "data.h"

using namespace std;

void showMainMenu() {
    cout << "\nMovie Collection Manager\n";
    cout << "1. Show all movies\n";
    cout << "2. Add movie\n";
    cout << "3. Sort movies by title\n";
    cout << "4. Sort movies by year\n";
    cout << "5. Sort movies by rating\n";
    cout << "6. Search movie by title\n";
    cout << "7. Show total duration\n";
    cout << "0. Exit\n";
    cout << "Choose option: ";
}

void showAllMovies() {
    vector<Movie>& movies = getMovies();

    if (movies.empty()) {
        cout << "\nNo movies added yet.\n";
        return;
    }

    cout << "\nMovie list:\n";

    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". ";
        cout << movies[i].title << " | ";
        cout << movies[i].year << " | ";
        cout << movies[i].rating << "/10 | ";
        cout << movies[i].duration << " min\n";
    }
}

void showAddMovieMenu() {
    string title;
    int year;
    double rating;
    int duration;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nMovie title: ";
    getline(cin, title);

    cout << "Year: ";
    cin >> year;

    cout << "Rating 1-10: ";
    cin >> rating;

    cout << "Duration in minutes: ";
    cin >> duration;

    if (title.empty() || year < 1888 || rating < 1 || rating > 10 || duration <= 0) {
        cout << "\nInvalid movie data.\n";
        return;
    }

    addMovieLogic(title, year, rating, duration);
    cout << "\nMovie added successfully.\n";
}

void showSortMenu() {
    int choice;

    cout << "\nSort menu\n";
    cout << "1. By title\n";
    cout << "2. By year\n";
    cout << "3. By rating\n";
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1) {
        sortByTitle();
        cout << "\nMovies sorted by title.\n";
    }
    else if (choice == 2) {
        sortByYear();
        cout << "\nMovies sorted by year.\n";
    }
    else if (choice == 3) {
        sortByRating();
        cout << "\nMovies sorted by rating.\n";
    }
    else {
        cout << "\nInvalid sort option.\n";
    }
}

void showSearchMenu() {
    string title;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter movie title: ";
    getline(cin, title);

    int index = searchByTitle(title);

    if (index == -1) {
        cout << "\nMovie not found.\n";
        return;
    }

    vector<Movie>& movies = getMovies();

    cout << "\nMovie found:\n";
    cout << movies[index].title << " | ";
    cout << movies[index].year << " | ";
    cout << movies[index].rating << "/10 | ";
    cout << movies[index].duration << " min\n";
}

void showTotalDurationMenu() {
    int total = totalDurationRecursive(0);

    cout << "\nTotal duration of all movies: ";
    cout << total << " minutes\n";
}

void runApp() {
    int choice;

    do {
        showMainMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            showAllMovies();
            break;
        case 2:
            showAddMovieMenu();
            break;
        case 3:
        case 4:
        case 5:
            showSortMenu();
            break;
        case 6:
            showSearchMenu();
            break;
        case 7:
            showTotalDurationMenu();
            break;
        case 0:
            cout << "\nClosing program...\n";
            break;
        default:
            cout << "\nInvalid option.\n";
        }

    } while (choice != 0);
}