#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
public:

    int id;
    string name;
    string designation;
    float salary;
    string attendance;
};

vector<Employee> employees;

int nextId = 101;


// LOGIN SYSTEM
bool login()
{
    string username;
    string password;

    cout << "\n========== ADMIN LOGIN ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if(username == "admin" && password == "1234")
    {
        cout << "\nLogin Successful\n";

        return true;
    }

    else
    {
        cout << "\nInvalid Username or Password\n";

        return false;
    }
}


// ADD EMPLOYEE
void addEmployee()
{
    Employee emp;

    emp.id = nextId;

    nextId++;

    cin.ignore();

    cout << "\nEnter Employee Name: ";
    getline(cin, emp.name);

    cout << "Enter Designation: ";
    getline(cin, emp.designation);

    cout << "Enter Salary: ";
    cin >> emp.salary;

    cin.ignore();

    cout << "Attendance (Present/Absent): ";
    getline(cin, emp.attendance);

    employees.push_back(emp);

    cout << "\nEmployee Added Successfully\n";
}


// VIEW EMPLOYEES
void viewEmployees()
{
    if(employees.empty())
    {
        cout << "\nNo Employees Found\n";

        return;
    }

    cout << "\n========== EMPLOYEE LIST ==========\n";

    for(Employee emp : employees)
    {
        cout << "\nEmployee ID: " << emp.id << endl;

        cout << "Name: " << emp.name << endl;

        cout << "Designation: "
             << emp.designation << endl;

        cout << "Salary: "
             << emp.salary << endl;

        cout << "Attendance: "
             << emp.attendance << endl;

        cout << "----------------------------------\n";
    }
}


// SEARCH EMPLOYEE
void searchEmployee()
{
    int searchId;

    cout << "\nEnter Employee ID to Search: ";

    cin >> searchId;

    bool found = false;

    for(Employee emp : employees)
    {
        if(emp.id == searchId)
        {
            cout << "\nEmployee Found\n";

            cout << "Employee ID: "
                 << emp.id << endl;

            cout << "Name: "
                 << emp.name << endl;

            cout << "Designation: "
                 << emp.designation << endl;

            cout << "Salary: "
                 << emp.salary << endl;

            cout << "Attendance: "
                 << emp.attendance << endl;

            found = true;

            break;
        }
    }

    if(found == false)
    {
        cout << "\nEmployee Not Found\n";
    }
}


// UPDATE EMPLOYEE
void updateEmployee()
{
    int updateId;

    cout << "\nEnter Employee ID to Update: ";

    cin >> updateId;

    bool found = false;

    for(Employee &emp : employees)
    {
        if(emp.id == updateId)
        {
            cin.ignore();

            cout << "\nEnter New Name: ";
            getline(cin, emp.name);

            cout << "Enter New Designation: ";
            getline(cin, emp.designation);

            cout << "Enter New Salary: ";
            cin >> emp.salary;

            cin.ignore();

            cout << "Enter Attendance: ";
            getline(cin, emp.attendance);

            cout << "\nEmployee Updated Successfully\n";

            found = true;

            break;
        }
    }

    if(found == false)
    {
        cout << "\nEmployee Not Found\n";
    }
}


// DELETE EMPLOYEE
void deleteEmployee()
{
    int deleteId;

    cout << "\nEnter Employee ID to Delete: ";

    cin >> deleteId;

    bool found = false;

    for(int i = 0; i < employees.size(); i++)
    {
        if(employees[i].id == deleteId)
        {
            employees.erase(employees.begin() + i);

            cout << "\nEmployee Deleted Successfully\n";

            found = true;

            break;
        }
    }

    if(found == false)
    {
        cout << "\nEmployee Not Found\n";
    }
}


// SALARY SLIP
void generateSalarySlip()
{
    int id;

    cout << "\nEnter Employee ID: ";

    cin >> id;

    bool found = false;

    for(Employee emp : employees)
    {
        if(emp.id == id)
        {
            float bonus = emp.salary * 0.10;

            float tax = emp.salary * 0.05;

            float netSalary =
                emp.salary + bonus - tax;

            cout << "\n========== SALARY SLIP ==========\n";

            cout << "Employee ID: "
                 << emp.id << endl;

            cout << "Name: "
                 << emp.name << endl;

            cout << "Designation: "
                 << emp.designation << endl;

            cout << "Basic Salary: "
                 << emp.salary << endl;

            cout << "Bonus: "
                 << bonus << endl;

            cout << "Tax: "
                 << tax << endl;

            cout << "Net Salary: "
                 << netSalary << endl;

            found = true;

            break;
        }
    }

    if(found == false)
    {
        cout << "\nEmployee Not Found\n";
    }
}


// SAVE DATA
void saveToFile()
{
    ofstream file("employees.txt");

    for(Employee emp : employees)
    {
        file << emp.id << ","
             << emp.name << ","
             << emp.designation << ","
             << emp.salary << ","
             << emp.attendance << endl;
    }

    file.close();

    cout << "\nData Saved Successfully\n";
}


// LOAD DATA
void loadFromFile()
{
    ifstream file("employees.txt");

    Employee emp;

    string temp;

    while(getline(file, temp, ','))
    {
        emp.id = stoi(temp);

        getline(file, emp.name, ',');

        getline(file, emp.designation, ',');

        getline(file, temp, ',');

        emp.salary = stof(temp);

        getline(file, emp.attendance);

        employees.push_back(emp);

        if(emp.id >= nextId)
        {
            nextId = emp.id + 1;
        }
    }

    file.close();
}


// MAIN FUNCTION
int main()
{
    system("color 0A");

    if(login() == false)
    {
        return 0;
    }

    loadFromFile();

    int choice;

    do
    {
        system("cls");

        cout << "\n=====================================\n";
        cout << "     EMPLOYEE MANAGEMENT SYSTEM      \n";
        cout << "=====================================\n";

        cout << "\n1. Add Employee";
        cout << "\n2. View Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Update Employee";
        cout << "\n5. Delete Employee";
        cout << "\n6. Generate Salary Slip";
        cout << "\n7. Save Data";
        cout << "\n8. Exit";

        cout << "\n\nEnter Your Choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:

                system("cls");

                addEmployee();

                break;

            case 2:

                system("cls");

                viewEmployees();

                break;

            case 3:

                system("cls");

                searchEmployee();

                break;

            case 4:

                system("cls");

                updateEmployee();

                break;

            case 5:

                system("cls");

                deleteEmployee();

                break;

            case 6:

                system("cls");

                generateSalarySlip();

                break;

            case 7:

                system("cls");

                saveToFile();

                break;

            case 8:

                saveToFile();

                cout << "\nThank You\n";

                break;

            default:

                cout << "\nInvalid Choice\n";
        }

        system("pause");

    } while(choice != 8);

    return 0;
}