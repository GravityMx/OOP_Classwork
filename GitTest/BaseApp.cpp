#include <iostream>
#include "dayType.h"

using namespace std;

int dayType::getDayFromIndex(int index) {
    return (index % 7 + 7) % 7; // Ensures positive result for negative numbers and wraps int around day count
}

// Basic constructor; defaults to Sunday
dayType::dayType() {
    currentDayIndex = 0;
}

// Constructor that accepts a specific day (string) as parameter
dayType::dayType(string day) {
    SetDay(day);
}

void dayType::SetDay(string day) {
    for (int i = 0; i < 7; ++i) {
        if (daysOfWeek[i] == day) {
            currentDayIndex = i;
            return;
        }
    }
    throw invalid_argument("Invalid day of the week.");
}

// GetDay function returns the current day as a string
string dayType::GetDay() {
    return daysOfWeek[currentDayIndex];
}

// GetNextDay returns the next day in the week as a string
string dayType::GetNextDay() {
    return daysOfWeek[getDayFromIndex(currentDayIndex + 1)];
}

// GetPreviousDay returns the previous day in the week as a string
string dayType::GetPreviousDay() {
    return daysOfWeek[getDayFromIndex(currentDayIndex - 1)];
}

// AddDays modifies the current day by adding a number of days, wrapping around as necessary
void dayType::AddDays(int numDays) {
    currentDayIndex = getDayFromIndex(currentDayIndex + numDays);
}

// Program testbed
int main() {
    // Test default constructor
    dayType day1;
    cout << "Default day: " << day1.GetDay() << endl;

    // Test constructor with parameter (Wednesday)
    dayType day2("Wednesday");
    cout << "Day set to: " << day2.GetDay() << endl;

    // Test next and previous days
    cout << "Next day after " << day2.GetDay() << ": " << day2.GetNextDay() << endl;
    cout << "Previous day before " << day2.GetDay() << ": " << day2.GetPreviousDay() << endl;

    // Set day to Monday and add 4 days
    day2.SetDay("Monday");
    day2.AddDays(4);
    std::cout << "Adding 4 days to Monday: " << day2.GetDay() << endl;

    // Set day to Tuesday and add 13 days
    day2.SetDay("Tuesday");
    day2.AddDays(13);
    cout << "Adding 13 days to Tuesday: " << day2.GetDay() << endl;
}
