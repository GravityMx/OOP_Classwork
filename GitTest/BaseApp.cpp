#include <iostream>

using namespace std;

// Employee Class
// Represents an employee with name, number, and hire date.

class Employee
{
private:
    string employeeName;
    int employeeNumber;
    string hireDate;

public:
    // Constructor to initialize employee details
    Employee(string name, int number, string date)
    {
        employeeName = name;
        employeeNumber = number;
        hireDate = date;
    }

    // Accessors and Mutators
    string getEmployeeName()
    {
        return employeeName;
    }
    void setEmployeeName(string name)
    {
        employeeName = name;
    }

    int getEmployeeNumber()
    {
        return employeeNumber;
    }
    void setEmployeeNumber(int number)
    {
        employeeNumber = number;
    }

    string getHireDate()
    {
        return hireDate;
    }
    void setHireDate(string date)
    {
        hireDate = date;
    }

    // Function to print employee details
    void print()
    {
        cout << "Name: " << employeeName << endl;
        cout << "Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;

    }
};

class ProductionWorker : public Employee
{
private:
    int shiftNum;
    double hourlyPayRate;

public:
    // Constructor
    ProductionWorker(string name, int number, string date, int shift, double payRate)
        : Employee(name, number, date) // Initialize base class
    {
        // Just learned how to use a functions input variable when it has the same name as a member variable
        shiftNum = shift;
        hourlyPayRate = payRate;
    }

    // Accessors and Mutators
    int getShift()
    {
        return shiftNum;
    }

    void setShift(int shiftNumber)
    {
        shiftNum = shiftNumber;
    }

    double getHourlyPayRate()
    {
        return hourlyPayRate;
    }

    void setHourlyPayRate(double payRate)
    {
        hourlyPayRate = payRate;
    }

    // Overridden Print Function
    void print()
    {
        Employee::print(); // Call base class print

        if (shiftNum == 1)
        {
            cout << "Shift: Day" << endl;
        }
        else if (shiftNum == 2)
        {
            cout << "Shift: Night" << endl;
        }
        else
        {
            cout << "Shift: Unknown" << endl;
        }

        cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
    }
};

class ShiftSupervisor : public Employee
{
private:
    double annualSalary;
    double annualBonus;

public:
    // Constructor
    ShiftSupervisor(string name, int number, string date, double salary, double bonus)
        : Employee(name, number, date) // Initialize base class
    {
        annualSalary = salary;
        annualBonus = bonus;
    }

    // Accessors and Mutators
    double getAnnualSalary()
    {
        return annualSalary;
    }

    void setAnnualSalary(double salary)
    {
        annualSalary = salary;
    }

    double getAnnualBonus()
    {
        return annualBonus;
    }

    void setAnnualBonus(double bonus)
    {
        annualBonus = bonus;
    }

    // Overridden Print Function
    void print()
    {
        Employee::print(); // Call base class print

        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Bonus: $" << annualBonus << endl;
    }
};

class TeamLeader : public ProductionWorker
{
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    // Constructor
    TeamLeader(string name, int number, string date, int shift, double payRate, double bonus, int reqHours, int attHours)
        : ProductionWorker(name, number, date, shift, payRate) // Initialize base class
    {
        monthlyBonus = bonus;
        requiredTrainingHours = reqHours;
        attendedTrainingHours = attHours;
    }

    // Accessors and Mutators
    double getMonthlyBonus()
    {
        return monthlyBonus;
    }

    void setMonthlyBonus(double bonus)
    {
        monthlyBonus = bonus;
    }

    int getRequiredTrainingHours()
    {
        return requiredTrainingHours;
    }

    void setRequiredTrainingHours(int reqHours)
    {
        requiredTrainingHours = reqHours;
    }

    int getAttendedTrainingHours()
    {
        return attendedTrainingHours;
    }

    void setAttendedTrainingHours(int attHours)
    {
        attendedTrainingHours = attHours;
    }

    // Overridden Print Function
    void print()
    {
        ProductionWorker::print(); // Call base class print

        cout << "Monthly Bonus: $" << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

int main()
{
    // Badic employee test
    Employee emp("John Doe", 1001, "2020-01-15");
    emp.print();
    cout << endl;

    // Production Worker test
    ProductionWorker pw("Jane Smith", 1002, "2021-05-20", 1, 20.5);
    pw.print();
    cout << endl;

    // Shift Supervisor test
    ShiftSupervisor ss("Mike Johnson", 1003, "2019-03-10", 60000.0, 5000.0);
    ss.print();
    cout << endl;

    // Team Leader test
    TeamLeader tl("Nepo Tisum", 1004, "2024-07-25", 2, 60.0, 900.0, 40, 35);
    tl.print();
    cout << endl;
}
