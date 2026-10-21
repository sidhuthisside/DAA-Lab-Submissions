#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

struct Movie {
    string title;
    float rating;
    int rel_year;
    int popul;
};

int partition(vector<Movie>& movies, int low, int high) {
    float pivot = movies[high].rating;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (movies[j].rating <= pivot) {
            i++;
            swap(movies[i], movies[j]);
        }
    }
    swap(movies[i + 1], movies[high]);
    return (i + 1);
}

void quickSort(vector<Movie>& movies, int low, int high) {
    if (low >= high) return;
    int pivot = partition(movies, low, high);
    quickSort(movies, low, pivot - 1);
    quickSort(movies, pivot + 1, high);
}

vector<Movie> loadMoviesFromCSV(const string& filename) {
    vector<Movie> movies;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error while opening: " << filename << endl;
        return movies;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string title, ratingstr, yearstr, popstr;

        getline(ss, title, ',');
        getline(ss, ratingstr, ',');
        getline(ss, yearstr, ',');
        getline(ss, popstr, ',');

        if (!title.empty()) {
            Movie m;
            m.title = title;
            m.rating = stof(ratingstr);
            m.rel_year = stoi(yearstr);
            m.popul = stoi(popstr);
            movies.push_back(m);
        }
    }
    return movies;
}

int main() {
    string filename = "movies_real_titles.csv";
    vector<Movie> movies = loadMoviesFromCSV(filename);

    if (movies.empty()) return 1;

    quickSort(movies, 0, movies.size() - 1);

    cout << "\nSorted Movies by Rating using Quick Sort:" << endl;
    cout << endl;
    cout << string(100, '-') << endl;
    cout << left << setw(55) << "Title"
         << setw(10) << "Rating"
         << setw(15) << "Release Year"
         << setw(12) << "Popularity" << endl;
    cout << string(100, '-') << endl;

    int rowsToPrint = min(50, (int)movies.size());

    for (int i = 0; i < rowsToPrint; i++) {
        const auto& m = movies[i];
        cout << left
             << setw(55) << m.title
             << setw(10) << m.rating
             << setw(15) << m.rel_year
             << setw(12) << m.popul << endl;
    }

    cout << string(100, '-') << endl;
    cout << "Total Movies: " << movies.size() << endl;
    cout << fixed << setprecision(1);
    cout << "Lowest Rating : " << movies[0].rating << endl;
    cout << "Highest Rating: " << movies[movies.size()-1].rating << endl;

    return 0;
}
