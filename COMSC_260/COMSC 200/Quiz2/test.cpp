#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Employee{
    string name;
    int hours;
    float wage;
};

int main(){
    vector<Employee> employees(2);
    employees[0].name = "Something";
}