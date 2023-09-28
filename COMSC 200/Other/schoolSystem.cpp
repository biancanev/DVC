#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course{
    int section;
    string name;
    float units;
    Teacher teacher;
    char grade;
};

class Person{
    public:
        int id;
        string fname;
        string lname;
        virtual void displayInfo(){
            cout << id << " " << fname << " " << lname << endl;
        }
};

class Student: public Person{
    vector<Course> courses;
    public:
        Student(){}
        virtual void displayInfo(){
            cout << id << " " << fname << " " << lname << endl << endl;
            cout << "Courses:" << endl;
            cout << "Course Name | Units | Grade | Instructor" << endl;
            cout << "----------------------------------------" << endl;
            for(Course course : courses){
                cout.width(12);
                cout << course.name << "(" << course.section << ")" << endl;
                cout.width(6);
                cout << course.units << endl;
                cout.width(7);
                cout << course.grade << endl;
                cout << course.teacher.lname << ",  " << course.teacher.fname << endl;
            }

            cout << endl << "GPA: " << calculateGPA() << endl;
            cout << "========================================" << endl;
            cout << "END OF STUDENT REPORT" << endl << endl;
        }

        float calculateGPA(){
            float gpa = 0;
            for(Course course : courses){
                switch(course.grade){
                    case 'A':

                        break;
                    case 'B':
                        break;
                    case 'C':
                        break;
                    case 'D':
                        break;
                    case 'F':
                        break;
                    default:
                        break;
                }
            }
        }

        void addCourse(){
            Course *newCourse = new Course;
            cout << "Enter course name:" << endl;
            getline(cin, newCourse->name);
        }


};

class Teacher : public Person{

};

int main(){
    vector<Person> people;
    while(true){
        char option;
        cout << "Menu" << endl;


        cin >> option;
        cin.ignore(1, '\n');
        switch(toupper(option)){
            case 'I':
                break;
            case 'D':
                break;
            case 'E':
                break;
            default:
                break;
        }
    }
}