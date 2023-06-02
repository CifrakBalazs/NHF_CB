#include "classWrite.h"
#include "file.h"
#include "picture.h"
#include "film_menu.h"
#include "series_main.h"
#include <string>
#include <vector>
using namespace std;


int main() {
    string films_fname = "films.csv";
    string series_fname = "series.csv";
    vector<Film> films=films_file_import(films_fname);
    vector<Series> series = series_file_import(series_fname);
    int choice;
    while (true) {
        cout << "Welcome to the Database!" << std::endl;
        cout << "1. Films " << std::endl;
        cout << "2. Series" << std::endl;
        cout << "3. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            film_menu(films);
            break;
        case 2:
            series_menu(series);
            break;
        case 3:
            films_file_export(films,films_fname);
            series_file_export(series,series_fname);
            return 0;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
        }

        cout << std::endl;
    }
    return 0;
}
