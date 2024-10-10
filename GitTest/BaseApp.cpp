#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void FillTable(ifstream& file, float (&table)[5][7], string (&names)[5]);

void ComputeTotals(float table[5][7], float(&totals)[5]);

void OutputFullTable(string names[5], float table[5][7], float totals[5]);

void OutputTopRow(int spacing);


int main()
{
    // Initialize main variables
    string names[5];

    float table[5][7];

    float totals[5];


    // Reference variables
    string(&refNames)[5] = names;  

    float(&refTable)[5][7] = table;       

    float(&refTotals)[5] = totals;        


    //String that holds file location
    string filePath = "C:/Users/kenda/Desktop/CollegeWork/ObjectOrientedProgramming/runners.txt";


    // Open the file
    ifstream file(filePath);


    // Fill the table and name variables using the given file
    FillTable(file, refTable, refNames);

    // Compute the total run time for each runner
    ComputeTotals(table, refTotals);

    // Print results to the screen
    OutputFullTable(names, table, totals);

    // Close the file
    file.close();
}

void FillTable(ifstream& file, float(&table)[5][7], string(&names)[5])  // Pass by reference
{
    int y = 0, x = 0;
    string line, word;
    
    while (getline(file, line))
    {
        istringstream iss(line);

        iss >> word;

        names[y] = word;

        while (x < 7)
        {
            iss >> word;

            table[y][x] = stof(word);

            x++;
        }

        y++;
        x = 0;
    }
}

void ComputeTotals(float table[5][7], float(&totals)[5])
{
    int x = 0, y = 0;
    float total = 0;

    while (y < 5)
    {
        while (x < 7)
        {
            total += table[y][x];
            x++;
        }

        // Set the total for this row
        totals[y] = total;

        // Reset total and x
        total = 0;
        x = 0;

        // Increment Y
        y++;
        
    }
}

void OutputFullTable(string names[5], float table[5][7], float totals[5])
{
    int y = 0, x = 0, fixedWidth = 14;

    OutputTopRow(fixedWidth);

    while (y < 5)
    {
        // Start table row with name
        cout << setw(fixedWidth) << names[y];

        while (x < 7)
        {
            cout << setw(fixedWidth) << table[y][x];
            x++;
        }

        // Print this persons total miles for the week
        cout << setw(fixedWidth) << totals[y];

        // Print this persons average miles per day for the week
        cout << setw(fixedWidth) << (totals[y] / 7);

        // Set x to 0 and increment y
        x = 0;
        y++;

        //Start a new line, double spaced
        cout << endl << endl;
    }


}

void OutputTopRow(int spacing)
{
    cout << setw(spacing) << "Name" << setw(spacing) << "Day 1" << setw(spacing) << "Day 2" << setw(spacing) << "Day 3" << setw(spacing) << "Day 4" << setw(spacing) << "Day 5" << setw(spacing) << "Day 6" << setw(spacing) << "Day 7" << setw(spacing) << "Total" << setw(spacing) << "Average" << endl << endl;
}

