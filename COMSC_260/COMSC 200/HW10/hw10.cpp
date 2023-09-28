/**
 * We use cin.clear(); and cin.ignore(32768, '\n'); to make sure that we don't include any whitespace or extra characters in our input.
 * cin.ignore() will get rid of any newlines ad cin.clear will make sure that there is no extra chacters when we do our cin
 * 
 * **/

#include <iomanip>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;
struct Student{
long long ssn;
string name;
char gender;
};

class StudentMgr
{
private:
//vector<Student> sList;
map <long long, Student> studMap;

void insertStudent(long long, string, char);
void updateStudent(long long, string, char);
void deleteStudent(long long);

public:
StudentMgr();
~StudentMgr();
void displayStudent(long long);
void displayAll();
};

StudentMgr::StudentMgr()
{
/// TO DO: Add your code here
/// In each iteration of a while loop do the following:
/// Conduct an action. An action is one the following
/// 'I' - Insert the record. Use push_back to add the record to the end
/// of the vector sList. Sort the vector after all records are added.
/// If you use map, it does not have to be sorted.
///  'U' - Update the record
///  'D' - Delete the record
    ifstream inputFile;
    inputFile.open("studentRecords2.txt", ios::in);
    while(!inputFile.eof()){
        char opt, gender;
        long long ssn;
        string name;
        inputFile >> opt >> ssn >> name >> gender;
        cout << "Student  SSN       Gender" << endl;
        cout << "-------------------------" << endl;
        cout.width(7);
        cout << name;
        cout.width(9);
        cout << ssn;
        cout.width(2);
        cout << gender << endl;
        try{
            if(ssn < 1010001 || ssn > 999999999){
                throw ssn;
            }
            switch(opt){
                case 'I':
                    insertStudent(ssn, name, gender);
                    break;
                case 'U':
                    updateStudent(ssn, name, gender);
                    break;
                case 'D':
                    deleteStudent(ssn);
                    break;
                default:
                    throw "Invalid option" + opt;
                    break;
            }
        }catch(long long social){
            cout << "Invalid social security number " << social << " for " << name << endl;
        }catch(char const* str){
            cout << str << endl;
    }

    }
}
StudentMgr::~StudentMgr(){}

void StudentMgr::insertStudent (long long ssn, string name, char gender)
{
/// TO DO: Add your code here
    Student tempStudent = {ssn, name, gender};
    if(!studMap.insert(pair<long long, Student>(ssn, tempStudent)).second){
        throw "Student already exists";
    }
}

void StudentMgr::updateStudent (long long ssn, string name, char gender)
{
/// TO DO: Add your code here
    std::map<long long, Student>::iterator foundStudent = studMap.find(ssn);
    if(foundStudent == studMap.end()){
        throw "Student not found";
    }
    foundStudent->second.name = name;
    foundStudent->second.gender = gender;
}
void StudentMgr::deleteStudent (long long ssn)
{
/// TO DO: Add your code here
    std::map<long long, Student>::iterator foundStudent = studMap.find(ssn);
    if(foundStudent == studMap.end()){
        throw "Student not found";
    }
    studMap.erase(foundStudent);
}

void StudentMgr::displayStudent(long long ssn)
{
/// TO DO: Add your code here
    std::map<long long, Student>::iterator foundStudent = studMap.find(ssn);
    if(foundStudent == studMap.end()){
        throw "Student not found";
    }
    cout << "Student  SSN       Gender" << endl;
    cout << "-------------------------" << endl;
    cout.width(8);
    cout << foundStudent->second.name;
    cout.width(10);
    cout << foundStudent->second.ssn;
    cout.width(2);
    cout << foundStudent->second.gender << endl;

}
void StudentMgr::displayAll()
{
/// TO DO: Add your code here
    cout << "Student  SSN       Gender" << endl;
    cout << "-------------------------" << endl;
    for(auto it = studMap.begin(); it != studMap.end(); ++it){
        cout.width(8);
        cout << it->second.name;
        cout.width(10);
        cout << it->second.ssn;
        cout.width(2);
        cout << it->second.gender << endl;
    }
}

int main()
{
    StudentMgr sm;
    char input;
    while (input != 'q'){
        cout << endl << endl << "Select an option:" << endl;
        cout << "-----------------" << endl << endl;
        cout << "A. Display all student info" << endl;
        cout << "S. Display specific student" << endl;
        cout << "Q. Quit the program" << endl;
        cout << "--------------------------------" << endl;
        cout << "Enter selection: ";
        cin >> input;
        cin.clear();
        cin.ignore(32768, '\n');
        input = tolower(input);
        switch (input) {
            case 'a':
                sm.displayAll();
                break;
            case 's':
                {
                cout << "Input SSN: ";
                long long ssn;
                cin >> ssn;
                cin.clear();
                cin.ignore(32768,'\n');
                sm.displayStudent(ssn);
                }
        }
    }
    return 0;
}