#pragma once

class DateSingle {
private:
    int value;                  // Current value
    int min;                    // Minimum allowable value
    int max;                    // Maximum allowable value
    DateSingle* linkedDateSingle; // Pointer to a linked DateSingle

public:
    // Constructor
    DateSingle(int value, int min, int max, DateSingle* linkedDateSingle = nullptr);

    // Overload Operators

    // Assignment operator
    DateSingle& operator=(int newValue);

    // Pre-increment operator
    DateSingle& operator++();

    // Post-increment operator
    DateSingle operator++(int);

    // Pre-decrement operator
    DateSingle& operator--();

    // Casting operator to int
    operator int() const;

    // Link to another DateSingle
    void Link(DateSingle* newLinkDateSingle);
};
