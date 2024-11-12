#include <iostream>

using namespace std;

// Employee Class
// Represents an employee with name, number, and hire date.

Class Employee
{
    private:
        string employeeName
        int employeeNumber
        string hireDate

    Public :
        // Constructor to initialize employee details
        Employee(string name, int number, string date)

            // Accessors and Mutators
            string getEmployeeName()
            void setEmployeeName(string name)

            int getEmployeeNumber()
            void setEmployeeNumber(int number)

            string getHireDate()
            void setHireDate(string date)

            // Function to print employee details
            void print()
                Print "Name: " + employeeName
                Print "Number: " + employeeNumber
                Print "Hire Date: " + hireDate
};

int main()
{
    cout << "Hello World!\n";
}
