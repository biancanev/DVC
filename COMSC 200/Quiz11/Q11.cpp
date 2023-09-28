#include <iostream>

using namespace std;

class Student
{
    int ID = 0;
    string Name = "";
    string Address = "";
    string phoneNum = "";
    public:
        //Default constructor
        Student(){
            //no setter functions called
        }
        ~Student(){
        }
        //Constructor with setters
        Student(int newID, string newName, string newAddress, string newPhoneNum){
            setID(newID);
            setName(newName);
            setAddress(newAddress);
            setPhoneNumber(newPhoneNum);
        }
        void setID(int newID){
            if(newID / 10000 < 10 && newID / 10000 >= 1)
                ID = newID;
            else{
                cout << newID << " is not a correct ID" << endl;
                ID = -1;
            }
        }
        void setName(string newName){
            Name = newName;
        }
        void setAddress(string newAddress){
            Address = newAddress;
        }
        void setPhoneNumber(string newPhoneNum){
            phoneNum = newPhoneNum;
        }
        int getID(){
            return ID;
        }
        string getName(){
            return Name;
        }
        string getAddress(){
            return Address;
        }
        string getPhoneNum(){
            return phoneNum;
        }
};

void display(Student **arr, int size);

int main()
{
    const int SIZE = 9;

    /// Declare an array for holding the pointers of Student objects
    /// Initialize all elements with nullptr
    Student * arrStud[SIZE] = {nullptr};

    /// Add the first student info
    arrStud[0] = new Student(12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454");
    ///
    /// Add the second student info
    arrStud[1] =  new Student(22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082");
    ///
    /// Add the third student info
    arrStud[2] = new Student(22779, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455", "925-765-8979");

    /// Add the fourth(error) student info
    //initialize empty stdent
    arrStud[3] = new Student;
    //individually call each setter
    arrStud[3]->setID(555556);
    arrStud[3]->setName("Err");
    arrStud[3]->setAddress("666 Main St. Walnut Creek, CA 94589");
    arrStud[3]->setPhoneNumber("510-555-6666");
    
    /// The following display() function will display the information of all students in the array
    /// The function should check if an element is null first. If it is not null, the information is displayed.
    display(arrStud, SIZE);

    for(int i = 0; i < SIZE; i++){
        //check if array element is not nullptr
        if(arrStud[i] != nullptr){
            Student *p = arrStud[i];
            //if there is an object, delete it
            delete p;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}

void display(Student **arr, int size){
    for(int i = 0; i < size; i++){
        if(arr[i]){
            //Display ID and name
            cout << arr[i]->getID() << " " << arr[i]->getName() << endl;
            //Display address
            cout << "Address: " << arr[i]->getAddress() << endl;
            //Display phone number
            cout << "Phone #: " << arr[i]->getPhoneNum() << endl << endl;
        }
    }
}