#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float calcDistance(float x1, float y1, float x2, float y2);

float calcRadius(float x1, float y1, float x2, float y2);

void calcCircumference(float radius, float& out);

void calcArea(float radius, float* out);

float inputWithPrompt(string str);

void outputWithPrompt(string str, float outNum);

// Create a globally used PI value required by assinment
float PI = 3.1416;

int main()
{
    // Inisialize FLoat Variables
    float x1, y1, x2, y2, radius, circum, area;

    // Do iniscialization for pointers and references 

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

float calcRadius(float x1, float y1, float x2, float y2)
{
    return calcDistance(x1, y1, x2, y2);
}

float calcDistance(float x1, float y1, float x2, float y2)
{
    return sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
}

void calcCircumference(float radius, float& out)
{
    out = radius * PI * 2;
}

void calcArea(float radius, float* out)
{
    *out = PI * powf(radius, 2);
}


float inputWithPrompt(string str)
{
    cout << str;

    float output;

    cin >> output;

    return output;
}

void outputWithPrompt(string str, float outNum)
{
    cout << str << outNum << "\n";
}
