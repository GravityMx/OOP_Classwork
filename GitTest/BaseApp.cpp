#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    // Member function to calculate area
    double getArea() {
        return width * height;
    }
};

class Triangle {

private:
    double leg1Len;
    double leg2Len;

public:

    Triangle(double l1, double l2) {
        leg1Len = l1;
        leg2Len = l2;
    }

    double getArea() {
        return (leg1Len * leg2Len) / 2;
    }

};

int main() {
    Rectangle rect(5.0, 3.0);
    cout << "Area of the rectangle: " << rect.getArea() << endl;

    Triangle tri(5.0, 3.0);
    cout << "Area of the triangle: " << tri.getArea() << endl;

    return 0;
}
