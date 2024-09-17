#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream file1("C:/Users/kenda/Desktop/CollegeWork/ObjectOrientedProgramming/Test1.3.txt");
    ifstream file2("C:/Users/kenda/Desktop/CollegeWork/ObjectOrientedProgramming/Test1.3_2.txt");
    ofstream output("C:/Users/kenda/Desktop/CollegeWork/ObjectOrientedProgramming/output.txt");

    vector<string> lines;
    string line;

    while (getline(file1, line))
    {
        lines.push_back(line);
    }

    while (getline(file2, line))
    {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());

    for (const auto& l : lines)
    {
        output << l << endl;
    }

    return 0;
}
