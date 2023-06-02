#ifndef FILM_MENU_H
#define FILM_MENU_H
#include <vector>
#include <string>
#include "picture.h"
#include "classWrite.h"
#include "file.h"
#include <iostream>

using namespace std;

int film_menu(vector<Film>& films);

void film_update(vector<Film>& films);

void film_delete(vector<Film>& films);

void new_film(vector<Film>& films);

void list_films(const vector<Film>& films);

#endif // !FILM_MENU_H
