#include "series_main.h"
#include <iostream>
#include <algorithm>


int series_menu(vector<Series>& seriesList) {
    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. List all series\n";
        cout << "2. Add a new series\n";
        cout << "3. Update a series\n";
        cout << "4. Delete a series\n";
        cout << "5. List all episodes of a series\n";
        cout << "6. Add a new episode to a series\n";
        cout << "7. Update an episode of a series\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeries(seriesList);
            break;
        case 2:
            addSeries(seriesList);
            break;
        case 3:
            updateSeries(seriesList);
            break;
        case 4:
            deleteSeries(seriesList);
            break;
        case 5: {
            string seriesName;
            cout << "Enter the name of the series: ";
            cin.ignore();
            getline(cin, seriesName);

            auto seriesIter = find_if(seriesList.begin(), seriesList.end(),
                [&](const Series& s) {
                    return s.getSeries_name() == seriesName;
                });

            if (seriesIter != seriesList.end()) {
                displayEpisodes(*seriesIter);
            }
            else {
                cout << "Series not found!\n";
            }

            break;
        }
        case 6: {
            string seriesName;
            cout << "Enter the name of the series: ";
            cin.ignore();
            getline(cin, seriesName);

            auto seriesIter = find_if(seriesList.begin(), seriesList.end(),
                [&](const Series& s) {
                    return s.getSeries_name() == seriesName;
                });

            if (seriesIter != seriesList.end()) {
                addEpisode(*seriesIter);
                seriesIter->updateAverages();
            }
            else {
                cout << "Series not found!\n";
            }

            break;
        }
        case 7: {
            string seriesName;
            cout << "Enter the name of the series: ";
            cin.ignore();
            getline(cin, seriesName);

            auto seriesIter = find_if(seriesList.begin(), seriesList.end(),
                [&](const Series& s) {
                    return s.getSeries_name() == seriesName;
                });

            if (seriesIter != seriesList.end()) {
                updateEpisode(*seriesIter);
                seriesIter->updateAverages();
            }
            else {
                cout << "Series not found!\n";
            }

            break;
        }
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void displaySeries(const vector<Series>& seriesList) {
    cout << "Series List:\n";
    for (const Series& series : seriesList) {
        cout << "Series Name: " << series.getSeries_name() << endl;
        cout << "Actors: ";
        for (const string& actor : series.getActors()) {
            cout << actor << ", ";
        }
        cout << endl;
        cout << "Average Viewers: " << series.getAvgViewers() << endl;
        cout << "Average Runtime: " << series.getAvgRuntime() << endl;
        cout << "No. of Seasons: " << series.getNoSeasons() << endl;
        cout << endl;
    }
}

void addSeries(vector<Series>& seriesList) {
    string seriesName;
    vector<string> actors;

    cout << "Enter the series name: ";
    cin.ignore();
    getline(cin, seriesName);

    cout << "Enter the actors (separated by commas): ";
    string actorsInput;
    getline(cin, actorsInput);

    string actor;
    stringstream ss(actorsInput);
    while (getline(ss, actor, ',')) {
        actors.push_back(actor);
    }

    seriesList.emplace_back(seriesName, actors);
}

void updateSeries(vector<Series>& seriesList) {
    string seriesName;
    cout << "Enter the name of the series to update: ";
    cin.ignore();
    getline(cin, seriesName);

    auto seriesIter = find_if(seriesList.begin(), seriesList.end(),
        [&](const Series& s) {
            return s.getSeries_name() == seriesName;
        });

    if (seriesIter != seriesList.end()) {
        Series& series = *seriesIter;

        string newSeriesName;
        cout << "Enter the new series name: ";
        getline(cin, newSeriesName);
        series.getSeries_name() = newSeriesName;

        vector<string> actors;
        cout << "Enter the new actors (separated by commas): ";
        string actorsInput;
        getline(cin, actorsInput);

        string actor;
        stringstream ss(actorsInput);
        while (getline(ss, actor, ',')) {
            actors.push_back(actor);
        }
        series.getActors() = actors;
    }
    else {
        cout << "Series not found!\n";
    }
}

void deleteSeries(vector<Series>& seriesList) {
    string seriesName;
    cout << "Enter the name of the series to delete: ";
    cin.ignore();
    getline(cin, seriesName);

    auto seriesIter = find_if(seriesList.begin(), seriesList.end(),
        [&](const Series& s) {
            return s.getSeries_name() == seriesName;
        });

    if (seriesIter != seriesList.end()) {
        seriesList.erase(seriesIter);
        cout << "Series deleted.\n";
    }
    else {
        cout << "Series not found!\n";
    }
}

void displayEpisodes(const Series& series) {
    cout << "Episodes of " << series.getSeries_name() << ":\n";
    for (const Episode& episode : series.getEpisodes()) {
        cout << "Title: " << episode.getTitle() << endl;
        cout << "Genre: " << episode.getGenre() << endl;
        cout << "Country of Origin: " << episode.getCountryOfOrigin() << endl;
        cout << "Certification: " << episode.getCertification() << endl;
        cout << "Director Name: " << episode.getDirectorName() << endl;
        cout << "Runtime: " << episode.getRuntime() << " minutes" << endl;
        cout << "Viewers: " << episode.getViewers() << endl;
        cout << "Average Rating: " << episode.getAvgRating() << endl;
        cout << "Season: " << episode.getSeason() << endl;
        cout << "Episode: " << episode.getEpisode() << endl;
        cout << endl;
    }
}

void addEpisode(Series& series) {
    string title, genre, countryofOrigin, certification, director_name;
    int runtime, viewers, season, episode;
    float avgRating;

    cout << "Enter the episode title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter the genre: ";
    getline(cin, genre);
    cout << "Enter the country of origin: ";
    getline(cin, countryofOrigin);
    cout << "Enter the certification: ";
    getline(cin, certification);
    cout << "Enter the director name: ";
    getline(cin, director_name);
    cout << "Enter the runtime (in minutes): ";
    cin >> runtime;
    cout << "Enter the number of viewers: ";
    cin >> viewers;
    cout << "Enter the average rating: ";
    cin >> avgRating;
    cout << "Enter the season number: ";
    cin >> season;
    cout << "Enter the episode number: ";
    cin >> episode;

    series.getEpisodes().emplace_back(title, genre, countryofOrigin, certification,
        director_name, runtime, viewers, avgRating,
        season, episode);

    series.updateAverages();
}

void updateEpisode(Series& series) {
    string episodeTitle;
    cout << "Enter the title of the episode to update: ";
    cin.ignore();
    getline(cin, episodeTitle);

    auto episodeIter = find_if(series.getEpisodes().begin(), series.getEpisodes().end(),
        [&](const Episode& e) {
            return e.getTitle() == episodeTitle;
        });

    if (episodeIter != series.getEpisodes().end()) {
        Episode& episode = *episodeIter;

        string title, genre, countryofOrigin, certification, director_name;
        int runtime, viewers, season, episodeNumber;
        float avgRating;

        cout << "Enter the new episode title: ";
        getline(cin, title);
        episode.setTitle(title);

        cout << "Enter the new genre: ";
        getline(cin, genre);
        episode.setGenre(genre);

        cout << "Enter the new country of origin: ";
        getline(cin, countryofOrigin);
        episode.setCountryOfOrigin(countryofOrigin);

        cout << "Enter the new certification: ";
        getline(cin, certification);
        episode.setCertification(certification);

        cout << "Enter the new director name: ";
        getline(cin, director_name);
        episode.setDirectorName(director_name);

        cout << "Enter the new runtime (in minutes): ";
        cin >> runtime;
        episode.setRuntime(runtime);

        cout << "Enter the new number of viewers: ";
        cin >> viewers;
        episode.setViewers(viewers);

        cout << "Enter the new average rating: ";
        cin >> avgRating;
        episode.setAvgRating(avgRating);

        cout << "Enter the new season number: ";
        cin >> season;
        episode.setSeason(season);

        cout << "Enter the new episode number: ";
        cin >> episodeNumber;
        episode.setEpisode(episodeNumber);

        series.updateAverages();
    }
    else {
        cout << "Episode not found!\n";
    }
}