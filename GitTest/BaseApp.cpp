#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

float Calculate(float num1, float num2, char opp)
{
    if (opp == '+')
    {
        return num1 + num2;
    }
    else if (opp == '-')
    {
        return num1 - num2;
    }
    else if (opp == '*')
    {
        return num1 * num2;
    }
    else if (opp == '/')
    {
        return num1 / num2;
    }
    else
    {
        cout << "BAD OPPERATOR";
        return 0;
    }
}

int CoreLoop()
{
    string input;

    cout << "Enter equation: ";
    std::getline(cin, input); 

    istringstream iss(input);
    vector<string> elements;
    string holder;

    while (iss >> holder)
    {
        elements.push_back(holder);
    }

    bool setNum1 = true;
    bool isNumber = true;

    float num1;
    float num2;
    char opp;

    for (int i = 0; i < elements.size(); i++)
    {
        if (isNumber)
        {
            if (setNum1)
            {
                num1 = stof(elements[i]);
                setNum1 = false;
            }
            else
            {
                num2 = stof(elements[i]);

                num1 = Calculate(num1, num2, opp);
            }
        }
        else
        {
            opp = elements[i][0];
        }

        isNumber = !isNumber;
    }

    cout << input << " = " << num1 << endl;
    return 0;
}

int main()
{
    while (true)
    {
        CoreLoop();
    }
}


