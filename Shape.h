#pragma once
#include <string>

namespace std {

    class Shape {
    private:
        float area;       // Shape's area (default is float now)
        string name;      // Name of the shape

    public:
        // Getters and setters for area
        float getArea() const { return area; }
        void setArea(float a) { area = a; }

        // Getters and setters for name
        string getName() const { return name; }
        void setName(const string& n) { name = n; }

        //Pure virtual function for calculating area
        virtual void calcArea() = 0;

        // Virtual destructor for cleanup
        virtual ~Shape() {}
    };

} // namespace std
