#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include <vector>

using namespace std;

int main() {
    // Create some shapes
    Rectangle rect1(10, 5, "Big Rectangle");
    Rectangle rect2(6, 8, "Small Rectangle");
    Circle circle1(0, 0, 4, "Small Circle");
    Circle circle2(1, 1, 7, "Big Circle");
    Square square1(4, "Perfect Square");

    // Store them in a vector of Shape pointers
    vector<Shape*> shapes = { &rect1, &rect2, &circle1, &circle2, &square1 };

    // Display all shapes' info
    for (const auto* shape : shapes) {
        cout << "Shape Name: " << shape->getName() << endl;
        cout << "Area: " << shape->getArea() << "\n" << endl;
    }

    return 0;
}