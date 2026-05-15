#pragma once
#include "data.h"

using namespace std;

void addMovieLogic(string title, int year, double rating, int duration);

void sortByTitle();
void sortByYear();
void sortByRating();

int searchByTitle(string title);

int totalDurationRecursive(int index);