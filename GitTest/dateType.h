#pragma once

#include "DateSingle.h" // Include DateSingle since it's used

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

};
