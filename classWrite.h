#ifndef CLASSWRITE_H
#define CLASSWRITE_H
#include <fstream>
#include <iostream>
#include <vector>
#include "picture.h"
using namespace std;

void films_write(const vector<Film>& films,ostream& output);

void episodes_write(const vector<Episode>& episodes, ostream& output);

void seriess_write(const vector<Series>& series, ostream& output);

void actors_write(const vector<string>& actors, ostream& output);
#endif