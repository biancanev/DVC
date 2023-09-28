/*
Part 2:
(A) List the code, which can cause segmentation fault, in the comment area on top of the main.cpp file. 

#include <iostream>
#include <string>
using namespace std;

struct Employee{
    string name;
    int hours;
    float wage;
};

int main(){
    vector<Employee> employees;
    employees[0].name = "Something";
}

(B) Write your reasoning as the comment at the top of the main.cpp file to explain the reason why segmentation fault may occur.

* The segmentation fault will occur ecause you have named the vector but have not initialized any elements to the vector itself.
Therefore, because in the code above we have initialized the vector but never assigned any memory allocation to it, the system 
cannot assign the attribute name and will throw a segmentation fault. To fix this, you must use a push_back function or
initialize it when defining.

Examples:

//Initialize while defining:
int main(){
    vector<Employee> employees(1);
    employees[0].name = "Something";
}

//using push_back():
int main(){
    vector<Employee> employees;
    Employee emp;
    employees.push_back(emp);
    employees[0].name = "Something";
}
*/

//Part 1 coding
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee{
    string name;
    int hours;
    float rate;
};

void inputEmployees(vector<Employee> &employees, int numEmployees);
void outputEmployees(vector<Employee> employees);

int main(){
    int numEmployees;
    cout << "How many employees do you have?" << endl;
    cin >> numEmployees;
    vector<Employee> employees;
    inputEmployees(employees, numEmployees);
    outputEmployees(employees);
}

void inputEmployees(vector<Employee> &employees, int numEmployees){
    for(int i = 0; i < numEmployees; i++){
        Employee newEmployee;
        cout << "Enter the employee #" << i + 1 << "'s name: ";
        cin >> newEmployee.name;
        cout << "Enter the employee #" << i + 1 << "'s wage rate: ";
        cin >> newEmployee.rate;
        cout << "Enter the employee #" << i + 1 << "'s hours: ";
        cin >> newEmployee.hours;
        employees.push_back(newEmployee);
    }
}

void outputEmployees(vector<Employee> employees){
    for(Employee existingEmployee : employees){
        cout << "Employee " << existingEmployee.name << " works at $" << existingEmployee.rate << " per hour for " << existingEmployee.hours << " hours" << endl;
        cout << "Therefore, they earn a gross income of $" << existingEmployee.rate * existingEmployee.hours << endl;
    }
}
