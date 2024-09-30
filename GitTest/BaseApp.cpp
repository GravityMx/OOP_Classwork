#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Create prototype funcitions

float calcDistance(float x1, float y1, float x2, float y2);

float calcRadius(float x1, float y1, float x2, float y2);

void calcCircumference(float radius, float& out);

void calcArea(float radius, float* out);

float inputWithPrompt(string str);

void outputWithPrompt(string str, float outNum);

// Create the globally used PI value required by assinment (I would make it static but I would probibly get points off for using techquines that have not been taught yet)

float PI = 3.1416;

int main()
{
    // Inisialize Float Variables
    float x1, y1, x2, y2, radius, circum, area;

    // Do iniscialization for pointers and references (I would use vector2's via SFML but I would probibly get points off for using techquines that have not been taught yet)

    float& circumRef = circum;

    float* areaPtr = &area;

    // Get points
    x1 = inputWithPrompt("Please ente the X value for the circles center point: ");
    y1 = inputWithPrompt("Please ente the Y value for the circles center point: ");
    x2 = inputWithPrompt("Please ente the X value for the point on the circles edge: ");
    y2 = inputWithPrompt("Please ente the Y value for the point on the circles edge: ");

    // Get the radius
    radius = calcRadius(x1, y1, x2, y2);

    // Get the circumference
    calcCircumference(radius, circumRef);

    // Get the area
    calcArea(radius, areaPtr);

    // Print the radius, circumference, and area of the circle
    outputWithPrompt("The radius of the circle is: ", radius);
    outputWithPrompt("The circumference of the circle is: ", circum);
    outputWithPrompt("The area of the circle is: ", area);
}

// Calcualtes the radius of a circle by getting the distance between a point on the edge of the circle and the center point of the circle
float calcRadius(float x1, float y1, float x2, float y2)
{
    return calcDistance(x1, y1, x2, y2);
}

// Calcualtes distance between two points
float calcDistance(float x1, float y1, float x2, float y2)
{
    return sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
}

// Calcualtes the circumference of a circle given the radius
void calcCircumference(float radius, float& out)
{
    out = radius * PI * 2;
}

// Calcualtes the area of a circle given the radius
void calcArea(float radius, float* out)
{
    *out = PI * powf(radius, 2);
}

// Prints a statement that prompts the user to input a float and returns it
float inputWithPrompt(string str)
{
    cout << str;

    float output;

    cin >> output;

    return output;
}

// Prints a statement that contains a string appended with a float and ending with the creation of a new line
void outputWithPrompt(string str, float outNum)
{
    cout << str << outNum << "\n";
}
