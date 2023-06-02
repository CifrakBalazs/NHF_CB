#ifndef SERIES_MAIN_H
#define SERIES_MAIN_H

#include <vector>
#include <string>
#include "picture.h"
#include "classWrite.h"
#include "file.h"
#include <iostream>

using namespace std;

int series_menu(vector<Series>& seriesList);

void displaySeries(const vector<Series>& seriesList);

void addSeries(vector<Series>& seriesList);

void updateSeries(vector<Series>& seriesList);

void deleteSeries(vector<Series>& seriesList);

void displayEpisodes(const Series& series);

void addEpisode(Series& series);

void updateEpisode(Series& series);

#endif // !SERIES_MAIN_H
