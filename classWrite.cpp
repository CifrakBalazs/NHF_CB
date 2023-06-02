#include "classWrite.h"
using namespace std;

void films_write(const vector<Film>& films, ostream& output){
    for (const Film& film : films) {
        output << film.getTitle() << ","
            << film.getGenre() << ","
            << film.getCountryOfOrigin() << ","
            << film.getCertification() << ","
            << film.getDirectorName() << ","
            << film.getRuntime() << ","
            << film.getViewers() << ","
            << film.getAvgRating() << ","
            << film.getBoxOfficeRevenue() << ","
            << film.getBudget() << ","
            << film.getState( )<< ","
            << film.getYearOfPremiere() << "\n";

    }

}

void episodes_write(const vector<Episode>& episodes,ostream& output) {
    for (const Episode& episode : episodes) {
        output << episode.getTitle() << ","
            << episode.getGenre() << ","
            << episode.getCountryOfOrigin() << ","
            << episode.getCertification() << ","
            << episode.getDirectorName() << ","
            << episode.getRuntime() << ","
            << episode.getViewers() << ","
            << episode.getAvgRating() << ","
            << episode.getEpisode() << ","
            << episode.getSeason() <<"\n";
    }

}

void seriess_write(const vector<Series>& seriess,ostream& output) {
    for (const Series& series : seriess) {
        output << series.getSeries_name() << ","
            << series.getAvgViewers() << ","
            << series.getAvgRuntime() << ","
            << series.getNoSeasons() << "\n";
    }
}

void actors_write(const vector<string>& actors, ostream& output) {
    for (const string& actor : actors) {
        output << actor;
    }
}