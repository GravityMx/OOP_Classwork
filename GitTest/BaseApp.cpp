#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Struct stores runners name and daily miles
struct Runner {
    string name;
    float miles[7];
    float total;
};

void FillTable(ifstream& file, Runner(&runners)[5]);

void ComputeTotals(Runner(&runners)[5]);

void OutputFullTable(Runner runners[5]);

void OutputTopRow(int spacing);

int main()
{
    // Initialize array of Runner structs
    Runner runners[5];

    // String that holds file location
    string filePath = "C:/Users/kenda/Desktop/CollegeWork/ObjectOrientedProgramming/runners.txt";

    // Open the file
    ifstream file(filePath);

    // Fill the runners array using the given file
    FillTable(file, runners);

    // Compute the total run time for each runner
    ComputeTotals(runners);

    // Print results to the screen
    OutputFullTable(runners);

    // Close the file
    file.close();
}

void FillTable(ifstream& file, Runner(&runners)[5])
{
    int y = 0, x = 0;
    string line, word;

    while (getline(file, line))
    {
        istringstream iss(line);

        iss >> word;

        runners[y].name = word;

        while (x < 7)
        {
            iss >> word;

            runners[y].miles[x] = stof(word);

            x++;
        }

        y++;
        x = 0;
    }
}

void ComputeTotals(Runner(&runners)[5])
{
    for (int y = 0; y < 5; y++)
    {
        float total = 0;

        for (int x = 0; x < 7; x++)
        {
            total += runners[y].miles[x];
        }

        // Set the total for this runner
        runners[y].total = total;
    }
}

void OutputFullTable(Runner runners[5])
{
    int fixedWidth = 14;

    OutputTopRow(fixedWidth);

    for (int y = 0; y < 5; y++)
    {
        // Start table row with name
        cout << setw(fixedWidth) << runners[y].name;

        for (int x = 0; x < 7; x++)
        {
            cout << setw(fixedWidth) << runners[y].miles[x];
        }

        // Print this runner's total miles for the week
        cout << setw(fixedWidth) << runners[y].total;

        // Print this runner's average miles per day for the week
        cout << setw(fixedWidth) << (runners[y].total / 7);

        // Start a new line, double spaced
        cout << endl << endl;
    }
}

void OutputTopRow(int spacing)
{
    cout << setw(spacing) << "Name" << setw(spacing) << "Day 1" << setw(spacing) << "Day 2" << setw(spacing) << "Day 3" << setw(spacing) << "Day 4" << setw(spacing) << "Day 5" << setw(spacing) << "Day 6" << setw(spacing) << "Day 7" << setw(spacing) << "Total" << setw(spacing) << "Average" << endl << endl;
}
