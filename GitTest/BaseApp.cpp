#include <iostream>
#include "dateSingle.h"
#include "dateType.h"

using namespace std;


// Implementation for dateSingle

// Constructor for DateSingle with parameters 
DateSingle::DateSingle(int value, int min, int max, DateSingle* linkedDateSingle)
    : value(value), min(min), max(max), linkedDateSingle(linkedDateSingle) {}

// Overload opperaters
// = opp
DateSingle& DateSingle::operator=(int newValue) {
    if (newValue >= min && newValue <= max) {
        value = newValue;
    }
    return *this;
}

// pre ++ opp
DateSingle& DateSingle::operator++() {
    value++;
    if (value > max) {
        value = min;
        if (linkedDateSingle) {
            ++(*linkedDateSingle);
        }
    }
    return *this;
}

// post ++ opp
DateSingle DateSingle::operator++(int) {
    DateSingle temp = *this;
    ++(*this);
    return temp;
}

DateSingle& DateSingle::operator--() {
    value--;
    if (value < min) {
        value = max;
        if (linkedDateSingle) {
            --(*linkedDateSingle);
        }
    }
    return *this;
}

DateSingle::operator int() const {
    return value;
}

void DateSingle::Link(DateSingle* newLinkDateSingle) {
    linkedDateSingle = newLinkDateSingle;
}


// Date Type implementation
DateType::DateType()
    : day(1, 1, 31), month(1, 1, 12), year(1930, 1, 9999) {
    day.Link(&month);
    month.Link(&year);
}

DateType::DateType(int monthValue, int dayValue, int yearValue)
    : day(dayValue, 1, 31), month(monthValue, 1, 12), year(yearValue, 1, 9999){
    day.Link(&month);
    month.Link(&year);
}

void DateType::DisplayDate() const {
    cout << int(month) << " / "
        << int(day) << " / "
        << int(year) << endl;
}

DateType& DateType::operator++() {
    ++day;
    return *this;
}

DateType& DateType::operator++(int){
    DateType temp = *this;

    ++(*this);

    return temp;
}

DateType& DateType::operator--() {
    --day;
    return *this;
}


// Test code
int main()
{
    // Create the first date
    DateType date1 = DateType(9, 30, 1991);

    // Print it to console to test inicialization
    cout << "Date 1: ";
    date1.DisplayDate();

    // Create a second date
    DateType date2 = DateType(3, 14, 2009);

    // Print it t0 console to test again
    cout << "Date 2: ";
    date2.DisplayDate();

    // Increment date 1
    date1++;

    // Print that date one was incremented
    cout << endl << "Date 1 incremented!" << endl << endl;

    // Print to test increment
    cout << "Date 1: ";
    date1.DisplayDate();

    // Increment date 1 again
    date1++;

    // Print that date one was incremented
    cout << endl << "Date 1 incremented!" << endl << endl;

    // Print to test roll over
    cout << "Date 1: ";
    date1.DisplayDate();

    // Create a thrid date with no constructors
    DateType date3;

    // Print it to test creating a date type with no constructor
    cout << "Date 3: ";
    date3.DisplayDate();

    // Decrement date 3 
    --date3;

    // Print that date one was incremented
    cout << endl << "Date 3 decremented!" << endl << endl;

    // Print to test roll over
    cout << "Date3: ";
    date3.DisplayDate();
}
