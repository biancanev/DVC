/************************************
 * COMSC 200 HW1: Structs and Vectors
 * Name: Ryan Kwong
 * IDE(s): Visual Studio Code
 * Compiler(s): MinGW
************************************/
//include all the header files needed
#include <iostream> //for output
#include <fstream> //for file reading
#include <string> //for C++ string
#include <vector> //for vector operations
#include <iomanip> //for setprecision
#include <math.h> //for rounding

//use the std namespace
using namespace std;

//create data structure for courses
struct Course{
    string name; //name of the course
    int credits, score; //credits of course and score earned in course
    float grade; //grade earned in course
};

//create data structure for students
struct Student{
    int ID; //Student's ID
    string name; //Student's Name
    vector<Course> courses; //List of Courses Student Took
    float gpa; // Student's GPA
};

//define all function prototypes
float determineGrade(int score); //determine grade earned in class
void reportSummary(vector<Student> students); //output student info
int isInArray(vector<Student> students, int ID); //check if student in array
float calculateGPA(vector<Course> courses); //calculate student gpa

int main(){
    //initialize vector of students
    vector<Student> studentVector;
    //initialize input stream
    fstream inputStream;
    //open the file "StudentRecords.txt" and read
    inputStream.open("StudentRecords.txt", ios::in);
    //make sure file exists
    if(!inputStream.bad()){
        //read until end of file
        while(!inputStream.eof()){
            //initialze data structures for storage
            Student newStudent;
            Course newCourse;
            //read the serialized data and assign them to the correct data structure members
            inputStream >> newStudent.ID >> newStudent.name >> newCourse.name >> newCourse.credits >> newCourse.score;
            //calculte the grade for the course
            newCourse.grade = determineGrade(newCourse.score);
            //determine whether the student is already in the vector
            int index = isInArray(studentVector, newStudent.ID);
            //check to see if there is an ID match
            //if there is a match
            if(index != -1){
                //add the course to the vector of courses for that student
                studentVector[index].courses.push_back(newCourse);
            }
            //if there is no match
            else{
                //add the course for the new student
                newStudent.courses.push_back(newCourse);
                //add the student to the vector of students
                studentVector.push_back(newStudent);
            }
        }
    }else
        cout << "The file StudentRecords.txt does not exist in this directory" << endl;
    //print all students' info from the vector
    reportSummary(studentVector);
    //end program
    return 0;
};

/*******************************************************************************
 * Function: Determine the grade of a course based on the student's score in the
 * course.
*******************************************************************************/
float determineGrade(int score){
    if(score >= 100)
        return 4.0;
    if(score < 50)
        return 0.0;
    else
        return floor((score - 50)/10);
}

/*******************************************************************************
 * Function: Iterate through the vector of students. Output every student's info
 * in a table format.
*******************************************************************************/
void reportSummary(vector<Student> students){
    //iterate through the vector of students
    for(Student student : students){
        //Output ID and name
        cout << student.ID << " " << student.name << endl;
        //Table break
        cout << "==================" << endl;
        //Iterate through courses in the vector of courses
        for(Course course : student.courses){
            //Output course name, score and grade
            cout << course.name << " " << course.credits << " " << course.score << " " << setprecision(1) << fixed << course.grade << endl;
        }
        //Table break
        cout << "==================" << endl;
        //Output student's GPA
        cout << "GPA " << setprecision(2) << fixed << calculateGPA(student.courses) << endl << endl;
    }
}

/*******************************************************************************
 * Function: Determine whether a student is already in the vector of students.
*******************************************************************************/
int isInArray(vector<Student> students, int ID){
    //intialize vector index to -1 in case there is no ID match
    //iterate through the vector for linear search
    for(int i = 0; i < students.size(); i++){
        //check for ID matches
        if(students[i].ID == ID){
            return i;
        }
    }
    return -1;
}
/*******************************************************************************
 * Function: Calculate a student's GPA given their vector of courses.
*******************************************************************************/
float calculateGPA(vector<Course> courses){
    //initialize grade and credit totals
    float totalGrade = 0, totalCredits = 0;
    //iterate through courses in student courses
    for(Course course : courses){
        //add the product of the grade and credits to the grade total
        totalGrade += course.grade * course.credits;
        //add up the total amount of credits
        totalCredits += course.credits;
    }
    //return the total grade earned divided by the total credits for GPA
    return totalGrade / totalCredits;
}
