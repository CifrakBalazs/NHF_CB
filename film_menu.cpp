#include "film_menu.h"
#include <iostream>
using namespace std;

int film_menu(vector<Film>& films){
    int choice;
    while (true) {
        cout << "----Films----" << endl;
        cout << "1.List Films " << endl;
        cout << "2.New Film" << endl;
        cout << "3.Update a Film" << endl;
        cout << "4.Delete a Film" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            list_films(films);
            break;
        case 2:
            new_film(films);
            break;
        case 3:
            film_update(films);
            break;
        case 4:
            film_delete(films);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
        }

        cout << std::endl;
    }
    return 0;
}


void film_update(vector<Film>& films) {
    if (films.empty()) {
        cout << "No films in the database." << endl;
        return;
    }

    // Prompt the user to enter the title of the film to update
    string title;
    cout << "Enter the title of the film to update: ";
    getline(cin, title);

    // Search for the film in the vector
    for (Film& film : films) {
        if (film.getTitle() == title) {
            // Prompt the user to enter updated film details
            string newTitle, newGenre, newCountryOfOrigin, newCertification, newDirectorName, newState;
            int newRuntime, newYearOfPremiere;
            long int newViewers, newBoxOfficeRevenue, newBudget;
            float newAvgRating;
            vector<string> newActors;

            cout << "Enter the new title of the Film: ";
            getline(cin, newTitle);

            cout << "Enter the new genre of the Film: ";
            getline(cin, newGenre);

            cout << "Enter the new country of origin of the Film: ";
            getline(cin, newCountryOfOrigin);

            cout << "Enter the new certification of the Film: ";
            getline(cin, newCertification);

            cout << "Enter the new director's name of the Film: ";
            getline(cin, newDirectorName);

            cout << "Enter the new runtime of the Film (in minutes): ";
            cin >> newRuntime;

            cout << "Enter the new number of viewers of the Film: ";
            cin >> newViewers;

            cout << "Enter the new average rating of the Film: ";
            cin >> newAvgRating;

            cin.ignore(); // Ignore the newline character left in the input stream

            cout << "Enter the new actors of the Film (separated by commas): ";
            string actorList;
            getline(cin, actorList);

            size_t pos = 0;
            string delimiter = ",";
            while ((pos = actorList.find(delimiter)) != string::npos) {
                string actor = actorList.substr(0, pos);
                newActors.push_back(actor);
                actorList.erase(0, pos + delimiter.length());
            }
            newActors.push_back(actorList);

            cout << "Enter the new box office revenue of the Film: ";
            cin >> newBoxOfficeRevenue;

            cout << "Enter the new budget of the Film: ";
            cin >> newBudget;

            cin.ignore(); // Ignore the newline character left in the input stream

            cout << "Enter the new state of the Film: ";
            getline(cin, newState);

            cout << "Enter the new year of premiere of the Film: ";
            cin >> newYearOfPremiere;

            cin.ignore(); // Ignore the newline character left in the input stream

            // Update the film object with the new details
            film.setTitle(newTitle);
            film.setGenre(newGenre);
            film.setCountryOfOrigin(newCountryOfOrigin);
            film.setCertification(newCertification);
            film.setDirectorName(newDirectorName);
            film.setRuntime(newRuntime);
            film.setViewers(newViewers);
            film.setAvgRating(newAvgRating);
            film.setActors(newActors);
            film.setBoxOfficeRevenue(newBoxOfficeRevenue);
            film.setBudget(newBudget);
            film.setState(newState);
            film.setYearOfPremiere(newYearOfPremiere);

            cout << "Film updated successfully!" << endl;
            return;
        }
    }

    cout << "Film not found in the database." << endl;
}

void film_delete(vector<Film>& films) {
    if (films.empty()) {
        cout << "No films in the database." << endl;
        return;
    }

    // Prompt the user to enter the title of the film to delete
    string title;
    cout << "Enter the title of the film to delete: ";
    getline(cin, title);

    // Search for the film in the vector
    for (auto it = films.begin(); it != films.end(); ++it) {
        if (it->getTitle() == title) {
            // Remove the film from the vector
            it = films.erase(it);
            cout << "Film deleted successfully!" << endl;
            return;
        }
    }

    cout << "Film not found in the database." << endl;
}

void new_film(vector<Film>& films) {
    string title, genre, countryOfOrigin, certification, directorName, state;
    int runtime, yearOfPremiere;
    long int viewers, boxOfficeRevenue, budget;
    float avgRating;
    vector<string> actors;

    cout << "Enter the title of the Film: ";
    getline(cin, title);

    cout << "Enter the genre of the Film: ";
    getline(cin, genre);

    cout << "Enter the country of origin of the Film: ";
    getline(cin, countryOfOrigin);

    cout << "Enter the certification of the Film: ";
    getline(cin, certification);

    cout << "Enter the director's name of the Film: ";
    getline(cin, directorName);

    cout << "Enter the runtime of the Film (in minutes): ";
    cin >> runtime;

    cout << "Enter the number of viewers of the Film: ";
    cin >> viewers;

    cout << "Enter the average rating of the Film: ";
    cin >> avgRating;

    cin.ignore(); // Ignore the newline character left in the input stream

    cout << "Enter the actors of the Film (separated by commas): ";
    string actorList;
    getline(cin, actorList);

    size_t pos = 0;
    string delimiter = ",";
    while ((pos = actorList.find(delimiter)) != string::npos) {
        string actor = actorList.substr(0, pos);
        actors.push_back(actor);
        actorList.erase(0, pos + delimiter.length());
    }
    actors.push_back(actorList);

    cout << "Enter the box office revenue of the Film: ";
    cin >> boxOfficeRevenue;

    cout << "Enter the budget of the Film: ";
    cin >> budget;

    cin.ignore(); // Ignore the newline character left in the input stream

    cout << "Enter the state of the Film: ";
    getline(cin, state);

    cout << "Enter the year of premiere of the Film: ";
    cin >> yearOfPremiere;

    cin.ignore(); // Ignore the newline character left in the input stream

    // Create a new Film object and add it to the vector
    Film newFilm(title, genre, countryOfOrigin, certification, directorName, actors,runtime, viewers,
        avgRating,boxOfficeRevenue, budget, state, yearOfPremiere);
    films.push_back(newFilm);

    cout << "Film added successfully!" << endl;
}

void list_films(const vector<Film>& films) {
    if (films.empty()) {
        cout << "No films in the database." << endl;
        return;
    }

    cout << "===== Film List =====" << endl;
    for (const Film& film : films) {
        cout << "Title: " << film.getTitle() << endl;
        cout << "Genre: " << film.getGenre() << endl;
        cout << "Country of Origin: " << film.getCountryOfOrigin() << endl;
        cout << "Certification: " << film.getCertification() << endl;
        cout << "Director's Name: " << film.getDirectorName() << endl;
        cout << "Runtime: " << film.getRuntime() << " minutes" << endl;
        cout << "Viewers: " << film.getViewers() << endl;
        cout << "Average Rating: " << film.getAvgRating() << endl;
        cout << "Actors: ";
        for (const string& actor : film.getActors()) {
            cout << actor << ", ";
        }
        cout << endl;
        cout << "Box Office Revenue: " << film.getBoxOfficeRevenue() << endl;
        cout << "Budget: " << film.getBudget() << endl;
        cout << "State: " << film.getState() << endl;
        cout << "Year of Premiere: " << film.getYearOfPremiere() << endl;
        cout << "=====================" << endl;
    }
}