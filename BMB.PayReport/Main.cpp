// Pay Report
// Brandon Bullock

#include <iostream>
#include <conio.h>
using namespace std;

//Use the following Struct to represent an Employee:
struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

Employee* getEmployeeInfo()
{
    /*
        Prompt the user to enter the following information for each employee:

        ID (integer)
        First Name (string)
        Last Name (string)
        Hours Worked (float)
        Hourly Rate (float)
    */

    Employee* pointerEmployee = new Employee;

    //pointerEmployee[i]->ID = i + 1; // assign an ID to each employee based on their index in the array
    cout << "First Name: ";
    cin >> pointerEmployee->FirstName;
    cout << "Last Name: ";
    cin >> pointerEmployee->LastName;
    cout << "Hours Worked: ";
    cin >> pointerEmployee->HoursWorked;
    cout << "Hourly Rate: ";
    cin >> pointerEmployee->HourlyRate;

    return pointerEmployee;
}

void printReport(Employee* employees, int employeeCount)
{
    //Print a report that displays the weekly pay for each employee
    //The weekly pay for an employee is calculated as HoursWorked * HourlyRate.

    cout << "\n";

    float totalPay = 0.0f; // Variable to hold the total pay for all employees

    cout << "Pay Report\n";
    cout << "----------\n";
    for (int i = 0; i < employeeCount; i++)
    {
        Employee employee = employees[i];
        cout << "ID: " << employee.ID << "\n";
        cout << "First Name: " << employee.FirstName << "\n";
        cout << "Last Name: " << employee.LastName << "\n";
        cout << "Hours Worked: " << employee.HoursWorked << "\n";
        cout << "Hourly Rate: " << employee.HourlyRate << "\n";
        cout << "Weekly Pay: " << employee.HoursWorked * employee.HourlyRate << "\n\n";
        totalPay += employee.HoursWorked * employee.HourlyRate; // Add the weekly pay for each employee to the total pay
    }

    //Print the total pay for all employees. The total pay for all employees is the sum of the weekly pay for each employee.
    cout << "Total Pay for All Employees: " << totalPay << endl;

}

int main()
{
    // Ask the user to enter the number of employees to process.You can assume that the user will enter a valid integer.
    cout << "Enter the number of employees: ";
    int employeeCount = 0; // "normal" integer Variable to hold the number of employees & initialize it to 0
    cin >> employeeCount;
    cout << "\n";

    //Create an array of Employee structs: 1.Define an array that holds number of employees entered by the user. Not use a global variable for the array.
    Employee* employees = new Employee[employeeCount]; // Dynamically allocate an array of Employee structs based on the number of employees entered by the user]

    for (int i = 0; i < employeeCount; i++)
    {
        cout << "******  Employee " << i + 1 << ".\n";
        employees[i] = *getEmployeeInfo(); // Call the getEmployeeInfo function to get the employee information and store it in the array		
    }
    
	// Call the printReport function to print the report for each employee then total the pay for all employees.
    printReport(employees, employeeCount); 

    (void)_getch();
    return 0;
}