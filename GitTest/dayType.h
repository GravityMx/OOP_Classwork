#pragma once

#include <string>
using namespace std;

class dayType
{
    private:
        string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        int currentDayIndex;

        // Helper function to wrap day index correctly
        int getDayFromIndex(int index);

    public:
        // Class Constructors
        dayType();

        dayType(string day);

        // Class modification functions
        void SetDay(string day);

        void AddDays(int numDays);

        // Class information fuctions
        string GetDay();

        string GetNextDay();

        string GetPreviousDay();
};

