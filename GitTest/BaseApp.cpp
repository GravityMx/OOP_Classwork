#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double principle, rate, time, finalSaving;

    cout << "Enter the initial amount: ";
    cin >> principle;

    cout << "Enter the annual interest rate: ";
    cin >> rate;

    cout << "Enter the number of times interest is compounded per year: ";
    cin >> time;

    finalSaving = principle * pow((1 + (rate / time)), time);

    cout << "The final savings at the end of the year is: " << finalSaving;
}
