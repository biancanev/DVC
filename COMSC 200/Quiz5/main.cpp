#include <iostream>

using namespace std;

struct Student
{
    int ID = 0;
    string Name = "";
    string Address = "";
    string phoneNum = "";
};

void display(Student * arr[], int size);

int main()
{
    const int SIZE = 9;

    /// Declare an array for holding the pointers of Student objects
    /// Initialize all elements with nullptr
    Student * arrStud[SIZE] = {nullptr};

    /// Add the first student info
    arrStud[0] = new Student;
    *arrStud[0] = {12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454"};
    
    arrStud[1] = new Student;
    *arrStud[1] = {22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082"};
    
    /// Add the third student info
    arrStud[2] = new Student;
    *arrStud[2] = {22779, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455", "925-765-8979"};
    
    /// The following display() function will display the information of all students in the array
    /// The function should check if an element is null first. If it is not null, the information is displayed.

    display(arrStud, SIZE);

    //Release all memory to prevent memory leaks
    //iterate through array
    for(int i = 0; i < SIZE; i++){
        //check if array element is not nullptr
        if(arrStud[i] != nullptr){
            //if there is an object, delete it
            delete arrStud[i];
        }
    }
    return 0;
}

void display(Student * arr[], int size){
    for(int i = 0; i < size; i++){
        if(arr[i]){
            //Display ID and name
            cout << arr[i]->ID << " " << arr[i]->Name << endl;
            //Display address
            cout << "Address: " << arr[i]->Address << endl;
            //Display phone number
            cout << "Phone #: " << arr[i]->phoneNum << endl;
        }
    }
}