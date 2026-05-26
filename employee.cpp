#include<iostream>
#include<vector>
#include<fstream>
#include<string>

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

// Login System
bool login()
{
    string username;
    string password;

    cout << "\n ========== ADMIN LOGIN ==========\n";
    cout << "Enter Your Username:";
    cin >> username;

    cout << "Enter Your Password:";
    cin >> password;

    if(username == "admin" && password == "admin@1234")
    {
        cout << "\nLogin Successfully\n";
        return true;
    }
    else{
        cout << "\n Invalid Username or Password\n";
        return false;
    }
}

// ADD EMPLOYEE
void addEmployee()
{
    Employee emp;

    cout << "\nEnter Employee ID: ";
    cin >> emp.id;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, emp.name);

    cout << "Enter Designation: ";
    getline(cin, emp.designation);

    cout << "Enter Salary: ";
    cin >> emp.salary;

    employees.push_back(emp);
    cout << "\n Employee Added Successfully\n";
}

// VIEW EMPLOYEES
void viewEmployees()
{
    if(employees.empty())
    {
        cout << "\n No Employees Found\n";
        return;
    }
    cout << "\n ======= Employee List ======\n";
    for(Employee emp : employees)
    {
        cout << "\nID: " << emp.id;
        cout << "\nName: " << emp.name;
        cout << "\nDesignation: " << emp.designation;
        cout << "\nSalary: " << emp.salary;
    }
}

// Search Employee
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

            cout << "ID: " << emp.id << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;

            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "\nEmployee Not Found\n";
    }
    
}


int main()
{
    int choice;

    do
    {
        cout << "\n ===== EMPLOYEE MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Employee\n";
        cout << "2. View Employee\n";
        cout << "3. Exit \n";

        cout << "\n Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                cout << "\n Thank You\n";
                break;
            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 3);
    return 0;
}