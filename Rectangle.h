#pragma once
#include "Shape.h"

namespace std {

    class Rectangle : public Shape {
    private:
        float length; // Length of the rectangle
        float width;  // Width of the rectangle

    public:
        // Constructor
        Rectangle(float l, float w, const string& n = "Rectangle")
            : length(l), width(w) {
            setName(n); // Set the shape's name
            calcArea(); // Calculate the area right away
        }


        // Override calcArea
        void calcArea() override {
            float area = length * width; // Just length * width
            setArea(area); // Save area in the base class
        }

        // Getters for length and width
        float getLength() const { return length; }
        float getWidth() const { return width; }
    };

} // namespace std
