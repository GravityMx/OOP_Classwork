#pragma once


#include "Rectangle.h"

using namespace std;


class Square : public Rectangle {
private:
    float side; // All sides are the same for a square

public:
    // Constructor
    Square(float s, const string& n = "Square")
        : Rectangle(s, s, n), side(s) {
        setName(n); // Set the shape's name
    }

    // Since a square is just a rectangle with all 
    // side being equal, I call the Rectangle constructor 
    // with the both side length parameters being equal


    // Getter for side
    float getSide() const { return side; }
};
