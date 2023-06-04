#include "file.h"
#include "picture.h"
#include "classWrite.h"
using namespace std;

vector<string> actors_file_import(const string& filename) {
    vector<string> actors;

    ifstream file(filename);
    if (!file.is_open()) {
        // File opening failed
        return actors;
    }

    string line;

    while (getline(file, line)) {
        actors.push_back(line);
    }

    file.close();
    return actors;
}

vector<Film> films_file_import(const string& filename) {
    vector<Film> films;

    ifstream file(filename);
    if (!file.is_open()) {
        // File opening failed
        return films;
    }
    string addon("_actors.csv");
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string title_str,genre_str,country_of_origin_str,certification_str,
                    director_name_str,runtime,viewers_str,avg_rating_str,revenue_str,
                    budget_str,state_str,yearOfPremiere_str;

        if (getline(iss, title_str, ',') &&
            getline(iss, genre_str, ',') &&
            getline(iss, country_of_origin_str, ',') &&
            getline(iss, certification_str, ',') &&
            getline(iss, director_name_str, ',') &&
            getline(iss, runtime, ',') &&
            getline(iss, viewers_str, ',') &&
            getline(iss, avg_rating_str, ',')&&
            getline(iss, revenue_str, ',')&&
            getline(iss, budget_str, ',')&&
            getline(iss, state_str, ',')&&
            getline(iss, yearOfPremiere_str, ',')) {

            // Convert string values to appropriate types
            int rtime = stoi(runtime);
            int yearOP = stoi(yearOfPremiere_str);
            int viewers = stoi(viewers_str);
            int revenue = stoi(revenue_str);
            int budget = stoi(budget_str);
            float avg_rating = stof(avg_rating_str);

            string actors_file_name = title_str + addon;
            vector<string> actors;
            actors = actors_file_import(actors_file_name);

            Film new_film(title_str, genre_str, country_of_origin_str, certification_str, director_name_str,actors,rtime,viewers,avg_rating,revenue,budget, state_str,yearOP);
            films.push_back(new_film);
        }
    }

    file.close();
    return films;
}

vector <Series> series_file_import(const string& filename) {
    vector<Series> series_vector;

    ifstream file(filename);
    if (!file.is_open()) {
        return series_vector;
    }
    string line;
    string addon = "_episodes.csv";
    string addon_2 = "_actors.csv";
    while (getline(file, line)) {
        istringstream iss(line);
        string series_name_str,avg_viewers_str,avg_runtime_str,no_seasons_str;
        vector<Episode> episode_vector;
        vector<string> actor_vector;

        if (getline(iss, series_name_str, ',') &&
            getline(iss, avg_viewers_str, ',') &&
            getline(iss, avg_runtime_str, ',') &&
            getline(iss, no_seasons_str, ',')) {

            // Convert string values to appropriate types
            float a_viewers = stof(avg_viewers_str);
            float a_runtime = stof(avg_runtime_str);
            int no_seasons = stoi(no_seasons_str);
            // Create Series object and add it to the vector
            episode_vector = episode_file_import(series_name_str+addon);
            actor_vector = actors_file_import(series_name_str + addon_2);
            Series new_series(series_name_str,episode_vector,actor_vector,a_viewers,a_runtime,no_seasons);
            new_series.updateAverages();
            series_vector.push_back(new_series);
        }
    }

    file.close();
    return series_vector;
}

vector<Episode> episode_file_import(const string& filename) {
    vector<Episode> episode_vector;

    ifstream file(filename);
    if (!file.is_open()) {
        // File opening failed
        return episode_vector;
    }
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string title_str, genre_str, country_of_origin_str, certification_str,
            director_name_str, runtime, viewers_str, avg_rating_str, season_str, episode_str;

        if (getline(iss, title_str, ',') &&
            getline(iss, genre_str, ',') &&
            getline(iss, country_of_origin_str, ',') &&
            getline(iss, certification_str, ',') &&
            getline(iss, director_name_str, ',') &&
            getline(iss, runtime, ',') &&
            getline(iss, viewers_str, ',') &&
            getline(iss, avg_rating_str, ',') &&
            getline(iss, season_str, ',')&&
            getline(iss, episode_str, ',')) {


            // Convert string values to appropriate types
            int rtime = stoi(runtime);
            long int viewers = stol(viewers_str);
            float avg_rating = stof(avg_rating_str);
            int season = stoi(season_str);
            int episode = stoi(episode_str);

            // Create Series object and add it to the vector
            Episode new_episode(title_str, genre_str, country_of_origin_str, certification_str, director_name_str,rtime,viewers,avg_rating,season,episode);
            episode_vector.push_back(new_episode);
        }
    }

    file.close();
    return episode_vector;
}

void films_file_export(const vector<Film>& films, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Film& film : films) {
            film.write(film, file);
            string filename2 = film.getTitle() + "_actors.csv";
            ofstream file2(filename2);
            if (file2.is_open()) {
                actors_write(film.getActors(), file2);
                file2.close();
            }
            else
                throw runtime_error("Failed to open actors file: " + filename2);

        }

    }
    else {
        throw runtime_error("Failed to open the main file: " + filename);

    }
    file.close();
}

void series_file_export(const vector<Series>& seriess, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Series& series : seriess) {
            series.write(file);
            string filename2 = series.getSeries_name() + "_actors.csv";
            ofstream file2(filename2);
            if (file2.is_open()) {
                actors_write(series.getActors(), file2);
                file2.close();
            }
            else {
                throw runtime_error("Failed to open actors file: " + filename2);
            }
            string filename3 = series.getSeries_name() + "_episodes.csv";
            ofstream file3(filename3);
            if (file3.is_open()) {
                episodes_write(series.getEpisodes(), file3);
                file3.close();
            }
            else {
                throw runtime_error("Failed to open episodes file: " + filename3);
            }
        }
    }
    else {
        throw runtime_error("Failed to open main file: " + filename);
    }
    file.close();
}

void episode_file_export(const vector<Episode>& episodes, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        episodes_write(episodes, file);
        file.close();
    }
    else {
        throw "Failed to open file";
    }
}

void actors_file_export(const std::vector<string>& actors, const std::string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        actors_write(actors, file);
        file.close();
    }
    else {
        throw "Failed to open file";
    }
}
