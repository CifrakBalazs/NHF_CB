#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <sstream>
#include <vector>
#include "picture.h"
using namespace std;

vector<string> actors_file_import(const string& filename);

vector<Film> films_file_import(const string& filename);

vector <Series> series_file_import(const string& filename);

vector<Episode> episode_file_import(const string& filename);

void films_file_export(const vector<Film>& films, const string& filename);

void series_file_export(const vector<Series>& seriess, const string& filename);

void episode_file_export(const vector<Episode>& episodes, const string& filename);

void actors_file_export(const vector<string>& actors, const string& filename);

#endif