#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include <string>
using namespace std;
#include <iostream>

class Picture {
    string title;
    string genre;
    string countryofOrigin;
    string certification;
    string director_name;
    int runtime; //runtime in minutes
    int viewers;
    float avgRating;
public:

    // Parameterized constructor
    Picture(string picTitle, string picGenre, string country, string cert, string dir,
        int picRuntime,  int picViewers, float rating) {
        title = picTitle;
        genre = picGenre;
        countryofOrigin = country;
        certification = cert;
        director_name = dir;
        runtime = picRuntime;
        viewers = picViewers;
        avgRating = rating;
    }
    // Copy constructor
    Picture(const Picture& other) {
        title = other.title;
        genre = other.genre;
        countryofOrigin = other.countryofOrigin;
        certification = other.certification;
        director_name = other.director_name;
        runtime = other.runtime;
        viewers = other.viewers;
        avgRating = other.avgRating;
    }

    // Setters
    void setTitle(const string& t) {
        title = t;
    }

    void setGenre(const string& g) {
        genre = g;
    }

    void setCountryOfOrigin(const string& country) {
        countryofOrigin = country;
    }

    void setCertification(const string& cert) {
        certification = cert;
    }

    void setDirectorName(const string& d) {
        director_name = d;
    }


    void setRuntime(int r) {
        runtime = r;
    }

    void setViewers( int v) {
        viewers = v;
    }

    void setAvgRating(float rating) {
        avgRating = rating;
    }

    // Getters
    string getTitle() const {
        return title;
    }

    string getGenre() const {
        return genre;
    }

    string getCountryOfOrigin() const {
        return countryofOrigin;
    }

    string getCertification() const {
        return certification;
    }

    string getDirectorName() const {
        return director_name;
    }

    int getRuntime() const {
        return runtime;
    }

    int getViewers() const {
        return viewers;
    }

    float getAvgRating() const {
        return avgRating;
    }

    // Destructor
    ~Picture() {}
};

class Film : public Picture {
    vector<string> actors;
    int boxOfficeRevenue;
    int budget;
    string state;
    int yearOfPremiere;
public:

    // Parameterized constructor
    Film(string filmTitle, string filmGenre, string country, string cert, string dir,
        vector<string>& actorList, int filmRuntime,  int filmViewers, float rating,
         int revenue,  int filmBudget, string filmState, int premiereYear) :
        Picture(filmTitle, filmGenre, country, cert, dir, filmRuntime, filmViewers, rating) {
        boxOfficeRevenue = revenue;
        budget = filmBudget;
        state = filmState;
        actors = actorList;
        yearOfPremiere = premiereYear;
    }
    // Copy constructor
    Film(const Film& other) : Picture(other) {
        boxOfficeRevenue = other.boxOfficeRevenue;
        budget = other.budget;
        state = other.state;
        actors = other.actors;
        yearOfPremiere = other.yearOfPremiere;
    }
    // Setters
    void setBoxOfficeRevenue(long int revenue) {
        boxOfficeRevenue = revenue;
    }

    void setBudget( int b) {
        budget = b;
    }

    void setState(const string& s) {
        state = s;
    }

    void setActors(const std::vector<string>& a) {
        actors = a;
    }

    void setYearOfPremiere(int year) {
        yearOfPremiere = year;
    }
    // Getters
    long int getBoxOfficeRevenue() const {
        return boxOfficeRevenue;
    }

     int getBudget() const {
        return budget;
    }

    string getState() const {
        return state;
    }

    vector<string> getActors() const {
        return actors;
    }

    int getYearOfPremiere() const {
        return yearOfPremiere;
    }

    void write(const Film& film, ostream& output) const {
        output << film.getTitle() << ','
            << film.getGenre() << ','
            << film.getCountryOfOrigin() << ','
            << film.getCertification() << ','
            << film.getDirectorName() << ','
            << film.getRuntime() << ','
            << film.getViewers() << ','
            << film.getAvgRating() << ','
            << film.getBoxOfficeRevenue() << ','
            << film.getBudget() << ','
            << film.getState() << ','
            << film.getYearOfPremiere() << '\n';
    }
    // Destructor
    ~Film() {}
};

class Episode : public Picture {
    int season;
    int episode;
public:


    // Parameterized constructor
    Episode(string episodeTitle, string episodeGenre, string country, string cert, string dir,
        int episodeRuntime,  int episodeViewers, float rating,
        int epSeason, int epEpisode) :
        Picture(episodeTitle, episodeGenre, country, cert, dir, episodeRuntime, episodeViewers, rating) {
        season = epSeason;
        episode = epEpisode;
    }
    // Copy constructor
    Episode(const Episode& other) : Picture(other) {
        season = other.season;
        episode = other.episode;
    }

    // Setters
    void setSeason(int s) {
        season = s;
    }

    void setEpisode(int e) {
        episode = e;
    }

    // Getters
    int getSeason() const {
        return season;
    }

    int getEpisode() const {
        return episode;

    }
    void write(const Episode& episode, ostream& output) const{
        output << episode.getTitle() << ","
            << episode.getGenre() << ","
            << episode.getCountryOfOrigin() << ","
            << episode.getCertification() << ","
            << episode.getDirectorName() << ","
            << episode.getRuntime() << ","
            << episode.getViewers() << ","
            << episode.getAvgRating() << ","
            << episode.getEpisode() << ","
            << episode.getSeason() << "\n";

    }
    // Destructor
    ~Episode() {}
};

class Series {
    string series_name;
    vector<Episode> episodes;
    vector<string> actors;
    float avg_viewers;
    float avg_runtime;
    int no_seasons;
public:

    // Parameterized constructor
    Series(string series_name, vector<string> actors)
            : series_name(series_name), actors(actors), avg_viewers(0),
              avg_runtime(0), no_seasons(0) {}

    Series(string series_name, vector<Episode> episodes,vector<string> actors, float avg_viewers, float avg_runtime, int no_seasons)
        : series_name(series_name), actors(actors), episodes(episodes),avg_viewers(avg_viewers),avg_runtime(avg_runtime),no_seasons(no_seasons){}
    // Copy constructor
    Series(const Series& other)
        : episodes(other.episodes), avg_viewers(other.avg_viewers), avg_runtime(other.avg_runtime),
        no_seasons(other.no_seasons), actors(other.actors) {}

    void updateAverages() {
        if (episodes.empty()) {
            avg_viewers = 0;
            avg_runtime = 0;
        }
        else {
            long int totalViewers = 0;
            int totalRuntime = 0;

            for (const Episode& episode : episodes) {
                totalViewers += episode.getViewers();
                totalRuntime += episode.getRuntime();
            }

            avg_viewers = static_cast<float>(totalViewers) / episodes.size();
            avg_runtime = static_cast<float>(totalRuntime) / episodes.size();
        }
    }
    
    // Getter for episodes
    vector<Episode> getEpisodes() const {
        return episodes;
    }

    string getSeries_name() const {
        return series_name;
    }

    void setSeries_name(const string& new_name) {
        series_name = new_name;
    }

    // Setter for episodes
    void setEpisodes(const vector<Episode>& episodes) {
        this->episodes = episodes;
    }

    // Getter for average viewers
    float getAvgViewers() const {
        return avg_viewers;
    }

    // Setter for average viewers
    void setAvgViewers(float avg_viewers) {
        this->avg_viewers = avg_viewers;
    }

    void setActors(const vector<string>& a) {
        actors = a;
    }

    vector<string> getActors() const {
        return actors;
    }

    // Getter for average runtime
    float getAvgRuntime() const {
        return avg_runtime;
    }

    // Setter for average runtime
    void setAvgRuntime(float avg_runtime) {
        this->avg_runtime = avg_runtime;
    }

    // Getter for number of seasons
    int getNoSeasons() const {
        return no_seasons;
    }

    // Setter for number of seasons
    void setNoSeasons(int no_seasons) {
        this->no_seasons = no_seasons;
    }
    void write(ostream& output) const{
     output << series_name << ","
            << avg_viewers<< ","
            << avg_runtime << ","
            << no_seasons << "\n";
    }
    ~Series() {}
};
#endif // 

