#include <iostream>
#include "dateSingle.h"
#include "dateType.h"
#include <ostream>
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

bool DateSingle::isValid(int testInput) const{
    return (min <= testInput && max >= testInput);
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

void DateType::SetDay(int newDay)
{
    day = newDay;
}

void DateType::SetMonth(int newMonth)
{
    month = newMonth;
}

void DateType::SetYear(int newYear)
{
    year = newYear;
}

bool DateType::SetDate(int day, int month, int year)
{
    this->SetDay(day);
    this->SetMonth(month);
    this->SetYear(year);

    return (this->day == day && this->month == month && this->year == year);
}

int DateType::GetDay()
{
    return day;
}

int DateType::GetMonth()
{
    return month;
}

int DateType::GetYear()
{
    return year;
}

void DateType::DisplayDate() const {
    cout << int(month) << " / "  << int(day) << " / "  << int(year) << endl;
}

bool DateType::isValid(int testDay, int testMonth, int testYear) const 
{
    return (day.isValid(testDay) && month.isValid(testMonth) && year.isValid(testYear));
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

DateType& DateType::operator--(int) {
    DateType temp = *this;

    --(*this);

    return temp;
}


ostream& operator<< (ostream& os, DateType& date)
{
    os << date.GetMonth() << " / " << date.GetDay() << " / " << date.GetYear();
    return os;
}

istream& operator>> (istream& is, DateType& date)
{
    char slash;
    int d, m, y;

    is >> m >> slash >> d >> slash >> y; // Parse input in MM/DD/YYYY format

    if (is) { // Ensure parsing succeeded
        
        // Check validity after parsing
        if (date.isValid(d, m, y)) {
            date.SetDay(d);
            date.SetMonth(m);
            date.SetYear(y);
        }
        else
        {
            is.setstate(std::ios::failbit); // Mark the stream as failed
        }

    }
    else
    {
        cout << "Failed to parse input!";
    }

    return is;
}

// Test code
int main() {
    // Create a date object using the default constructor and display the date using the first format
    DateType date1;
    date1.DisplayDate();

    // Create a date object using the constructor with parameters and display the date using the second format
    DateType date2(3, 14, 2009);
    cout << date2 << endl;

    // Use one of your date objects to test the setDate() function and display the result using the third format
    date1.SetDay(10);
    date1.SetMonth(4);
    date1.SetYear(2014);
    cout << date1 << endl;

    // Use setDate() to set the date to 13/45/2018 and verify that this date is not accepted
    if (!date1.SetDate(13, 45, 2018)) {
        cout << "Invalid date: 13/45/2018" << endl;
    }

    // Use setDate() to set the date to 4/31/2000 and verify that this date is not accepted
    if (!date1.SetDate(31, 4, 2000)) {
        cout << "Invalid date: 4/31/2000" << endl;
    }

    // Use setDate() to set the date to 2/29/2009 and verify that this date is not accepted
    if (!date1.SetDate(29, 2, 2009)) {
        cout << "Invalid date: 2/29/2009" << endl;
    }

    //Set the date to 2/29/2008, use the pre-decrement operator, and print the date
    date1.SetDate(29, 2, 2008);
    --date1;
    date1.DisplayDate();

    // Use the pre-increment operator, print the date
    ++date1;
    date1.DisplayDate();

    // Use the post-decrement and post-increment operators
    date1--;
    date1.DisplayDate();
    date1++;
    date1.DisplayDate();

    // Set the date to 12/31/2024, use the post-increment operator, print the date
    date1.SetDate(31, 12, 2024);
    date1++;
    date1.DisplayDate();

    // Use the post-decrement operator, print the date
    date1--;
    date1.DisplayDate();

    // Use the pre-increment and pre-decrement operators
    ++date1;
    date1.DisplayDate();
    --date1;
    date1.DisplayDate();

    //Use cin and the >> operator to read a date typed in at the keyboard
    cout << "Enter a date (MM/DD/YYYY): ";
    cin >> date1;

    // Use cout and the << operator to display the date
    cout << "Date entered: " << date1 << endl;

    return 0; 
}