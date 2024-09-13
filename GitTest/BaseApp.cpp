#include <iostream>
using namespace std;

int main() {
    double value1, value2, value3, total;

    cout << "Welcome to the calcalating percentages program!\n";

    cout << "Enter the first value: ";

    cin >> value1;

    cout << "Enter the second value: ";

    cin >> value2;

    cout << "Enter the third value: ";

    cin >> value3;

    total = value1 + value2 + value3;


    cout << "Percentage of value1: " << (value1 / total) * 100 << "%\n";
    cout << "Percentage of value2: " << (value2 / total) * 100 << "%\n";
    cout << "Percentage of value3: " << (value3 / total) * 100 << "%\n";
}
