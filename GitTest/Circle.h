#pragma once
#include "Shape.h"

using namespace std;

class Circle : public Shape {
private:
    float xCenter; // X-coordinate of the circle's center
    float yCenter; // Y-coordinate of the circle's center
    float radius;  // Radius of the circle

public:
    // Constructor
    Circle(float x, float y, float r, const string& n = "Circle")
        : xCenter(x), yCenter(y), radius(r) {
        setName(n); // Set the shape's name
        calcArea(); // Immediately calculate area when the object is created
    }

    // Override the calcArea function
    void calcArea() override {
        float area = 3.14159f * radius * radius; // Simple area calculation
        setArea(area); // Save area in the base class
    }

    // Getters for x, y, and radius
    float getXCenter() const { return xCenter; }
    float getYCenter() const { return yCenter; }
    float getRadius() const { return radius; }
};

