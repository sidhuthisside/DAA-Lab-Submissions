#include <iostream>
#include <iomanip>
using namespace std;

struct Item {
    int id;
    double weight;
    double profit;
    double ratio;
};

void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    Item items[100];

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Profit: ";
        cin >> items[i].profit;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    sortByRatio(items, n);

    cout << "\nItems sorted by Profit/Weight Ratio:\n";
    cout << string(50, '-') << endl;
    cout << left << setw(8) << "Item"
         << setw(12) << "Weight"
         << setw(12) << "Profit"
         << setw(12) << "Ratio" << endl;
    cout << string(50, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(8) << items[i].id
             << fixed << setprecision(2)
             << setw(12) << items[i].weight
             << setw(12) << items[i].profit
             << setw(12) << items[i].ratio << endl;
    }

    double remaining = capacity;
    double totalProfit = 0;

    cout << "\nFilling Knapsack:\n";
    cout << string(55, '-') << endl;
    cout << left << setw(8) << "Item"
         << setw(12) << "Fraction"
         << setw(16) << "Weight Taken"
         << setw(14) << "Profit Taken" << endl;
    cout << string(55, '-') << endl;

    for (int i = 0; i < n; i++) {
        if (remaining <= 0) break;

        double fraction, wTaken, pTaken;

        if (items[i].weight <= remaining) {
            fraction = 1.0;
            wTaken = items[i].weight;
            pTaken = items[i].profit;
            remaining -= items[i].weight;
        } else {
            fraction = remaining / items[i].weight;
            wTaken = remaining;
            pTaken = items[i].profit * fraction;
            remaining = 0;
        }

        totalProfit += pTaken;

        cout << left << setw(8) << items[i].id
             << fixed << setprecision(2)
             << setw(12) << fraction
             << setw(16) << wTaken
             << setw(14) << pTaken << endl;
    }

    cout << string(55, '-') << endl;
    cout << "Knapsack Capacity : " << capacity << endl;
    cout << "Total Weight Used : " << capacity - remaining << endl;
    cout << "Maximum Profit    : " << fixed << setprecision(2) << totalProfit << endl;
    cout << string(55, '-') << endl;

    return 0;
}
