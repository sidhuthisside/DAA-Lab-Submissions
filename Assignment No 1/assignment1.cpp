#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Faculty {
    string rank;
    string discipline;
    int yrsPhD;
    int yrsService;
    string sex;
    int salary;
};

void merge(vector<Faculty>& f, int left, int mid, int right) {
    vector<Faculty> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (f[i].salary <= f[j].salary)
            temp.push_back(f[i++]);
        else
            temp.push_back(f[j++]);
    }

    while (i <= mid)  temp.push_back(f[i++]);
    while (j <= right) temp.push_back(f[j++]);

    for (int k = 0; k < (int)temp.size(); k++)
        f[left + k] = temp[k];
}

void mergeSort(vector<Faculty>& f, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(f, left, mid);
    mergeSort(f, mid + 1, right);
    merge(f, left, mid, right);
}

int main() {
    vector<Faculty> faculty;

    ifstream file("Salaries.csv");
    if (!file.is_open()) {
        cout << "Error: Cannot open Salaries.csv" << endl;
        return 1;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string val;
        Faculty f;

        getline(ss, f.rank, ',');
        getline(ss, f.discipline, ',');
        getline(ss, val, ','); f.yrsPhD = stoi(val);
        getline(ss, val, ','); f.yrsService = stoi(val);
        getline(ss, f.sex, ',');
        getline(ss, val, ','); f.salary = stoi(val);

        faculty.push_back(f);
    }

    file.close();

    mergeSort(faculty, 0, faculty.size() - 1);

    cout << "\nFaculty Sorted by Salary (Ascending)\n";
    cout << "------------------------------------------------------\n";
    cout << left << setw(12) << "Rank"
         << setw(6)  << "Disc"
         << setw(8)  << "PhD"
         << setw(10) << "Service"
         << setw(8)  << "Sex"
         << "Salary\n";
    cout << "------------------------------------------------------\n";

    int limit = min(25, (int)faculty.size());
    for (int i = 0; i < limit; i++) {
        cout << left << setw(12) << faculty[i].rank
             << setw(6)  << faculty[i].discipline
             << setw(8)  << faculty[i].yrsPhD
             << setw(10) << faculty[i].yrsService
             << setw(8)  << faculty[i].sex
             << "$" << faculty[i].salary << "\n";
    }

    cout << "------------------------------------------------------\n";
    cout << "Total Records : " << faculty.size() << endl;
    cout << "Min Salary    : $" << faculty[0].salary << endl;
    cout << "Max Salary    : $" << faculty[faculty.size()-1].salary << endl;

    long long total = 0;
    for (int i = 0; i < (int)faculty.size(); i++) total += faculty[i].salary;
    cout << fixed << setprecision(2);
    cout << "Avg Salary    : $" << (double)total / faculty.size() << endl;

    return 0;
}
