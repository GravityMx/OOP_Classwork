#pragma once

#include "DateSingle.h" // Include DateSingle since it's used
#include <ostream>
#include <istream>
#include <sstream> 

using namespace std;

class DateType {
private:
    // Private variables
    DateSingle day;   
    DateSingle month; 
    DateSingle year;  

public:
    // Default Constructor
    DateType();

    // Constructor with parameters
    DateType(int day, int month, int year);

    // Display the date
    void DisplayDate() const;

    // Pre-increment operator
    DateType& operator++();

    // Post-increment operator
    DateType& operator++(int);

    // Pre-decrement operator
    DateType& operator--();

    // Post-decrement operator
    DateType& operator--(int);

    bool SetDate(int, int, int);

    void SetMonth(int newMonth);
    void SetDay(int newDay);
    void SetYear(int newYear);

    int GetMonth();
    int GetDay();
    int GetYear();


    // Check if the date is valid
    bool isValid(int, int, int) const;
};
