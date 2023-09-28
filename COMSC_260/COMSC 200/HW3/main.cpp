/**
 * Question 1: Why "#ifndef RECTANGE_H", "#define RECTANGLE_H" and "#endif" have to be added to the .h file?
 * This prevents the headerfile from being defined multiple times. The definition of the headerfile only gets defined(#define) if the preprocessor 
 * sees that it has not already been defined(#ifndef and #endif).
 * 
 * Question 2: Why the size of the array, i.e. 21, must be a const?
 * The system automatically allocates all the memory the array can take during compilation. If we do not set the size as a const, there is the possiblity
 * that the size may be changed. In this case, there will is the possibility that we have a size greater than the what the compiler allocated memoy for.
 * Therefore, we can run into segmentation errors where the program tries to access a memory address that the system did not allocate for.
 * 
 * Question 3: Why we prefer to let the array hold pointers to Rectangle, instead of objects?
 * This will save space while the array is not populated. If we defined the array to just hold Rectangle objects, it would automatically take up 1470 bytes
 * ((22 bytes * 3 strings + 4 bytes * 1 int) * 21 objects). However, if we define the array to hold pointers, the system will automatically allocate 84 bytes
 * (4 bytes * 21 pointers). Therefore, we can use dynamic memory allocation to use as little memory as possible if we do not populate the entire array. In
 * addition, we do not have to copy the entire array when passing it to a function. If we are given a function func1, if we were to pass a regular array of
 * objects, we would need to pass a copy of every object in the array. If we use an array of pointers, however, all we need to do is pass the addresses in
 * the array to func1, which saves memory as well.
**/

//iostream for output
#include <iostream>
//cstdlib for rand and srand functions for rng
#include <cstdlib>
//time for time function for seed
#include <time.h>
//header file for Rectangle class
#include "Rectangle.h"

using namespace std;

//set constant array size
const int SIZE = 21;

//function prototype
void display(Rectangle **);

int main(){
    //define seed
    srand(time(0));
    //create array of pointers to store all Rectangle classes
    Rectangle *arrRect[SIZE] = {nullptr};
    //populate the array
    for(int i = 0; i < SIZE; i++){
        //create a new Rectange with Dynamic Memory Allocation and generate random dimensions
        arrRect[i] = new Rectangle(rand() % 7 + 1, rand() % 7 + 1);
        //set the serial number based on index
        arrRect[i]->setSerialNumber(1000 + i);
    }
    //display all the rectangles in the array
    display(arrRect);
    //Delete all the pointers in the array
    for(int i = 0; i < SIZE; i++){
        //create temp pointer copy
        Rectangle *ptr = arrRect[i];
        //delete the pointer
        delete ptr;
    }
}

void display(Rectangle **arr){
    //Display all squares
    cout << "Square: " << endl;
    //table head
    cout << "Label   Width   Height" << endl;
    //iterate through the array
    for(int i = 0; i < SIZE; i++){
        //find the difference in dimensions
        int dif = arr[i]->getHeight() - arr[i]->getWidth();
        //if the dimensions are the same
        if(dif == 0){
            //output serial
            cout << "R" << arr[i]->getSerialNumber();
            //output width
            cout.width(8);
            cout << arr[i]->getWidth();
            //output heigh
            cout.width(9);
            cout << arr[i]->getHeight() << endl;
            //increment the static square counter
            arr[i]->incrementSquare();
        }
    }
    //table break
    cout << "======================" << endl;
    //output total squares using the static square counter
    cout << "Total: " << arr[0]->getSquareCount() << endl;
    //Display all vertical rectangles
    cout << "Vertical: " << endl;
    //table head
    cout << "Label   Width   Height" << endl;
    //iterate through the array
    for(int i = 0; i < SIZE; i++){
        //calculate the dimension difference
        int dif = arr[i]->getHeight() - arr[i]->getWidth();
        //if the height is greather than the width
        if(dif > 0){
            //output serial
            cout << "R" << arr[i]->getSerialNumber();
            cout.width(8);
            //output width
            cout << arr[i]->getWidth();
            cout.width(9);
            //output height
            cout << arr[i]->getHeight() << endl;
            //increment static vertical counter
            arr[i]->incrementVert();
        }
    }
    //table break
    cout << "======================" << endl;
    //display total vertical rectangles from the static vertical counter
    cout << "Total: " << arr[0]->getVertCount() << endl;
    //display all horizontal squares
    cout << "Horizonal: " << endl;
    //table head
    cout << "Label   Width   Height" << endl;
    //iterate through array
    for(int i = 0; i < SIZE; i++){
        //calculate dimension difference
        int dif = arr[i]->getHeight() - arr[i]->getWidth();
        //if the height is less than the width
        if(dif < 0){
            //output serial
            cout << "R" << arr[i]->getSerialNumber();
            cout.width(8);
            //output width
            cout << arr[i]->getWidth();
            cout.width(9);
            //output height
            cout << arr[i]->getHeight() << endl;
            //increment the static horizontal counter
            arr[i]->incrementHoriz();
        }
    }
    //table break
    cout << "======================" << endl;
    //outut total amount of horizontal rectangles based on the static horizontal counter
    cout << "Total: " << arr[0]->getHorizCount() << endl;
}