#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Shape{
    protected:
        int serialNumber;
    public:
        Shape(){
            setSerialNumber(0);
        }
        Shape(int serial){
            setSerialNumber(serial);
        }
        ~Shape(){}
        void setSerialNumber(int serial){
            this->serialNumber = serial;
        }
        int getSerialNumber(){
            return this->serialNumber;
        }
        virtual void displayInfo() = 0;
};

class Circle : public Shape{
    int radius = 1;
    public:
        Circle():Shape(){}
        Circle(int serial, int rad):Shape(serial){
            setRadius(rad);
        }
        void setRadius(int rad){
            this->radius = rad;
        }
        int getRadius(){
            return this->radius;
        }
        virtual void displayInfo(){
            cout << getSerialNumber() << endl;
            for(int i = -getRadius(); i <= getRadius(); i++){
                for(int j = -getRadius(); j <= 2 * getRadius(); j++){
                    if((int) sqrt(pow(i, 2) + pow(j, 2)) <= getRadius()){
                        cout << " * ";
                    }
                    else{
                        cout << "   ";
                    }
                }
                cout << "\n";
            }
        }
};

class Rectangle : public Shape{
    int width = 1;
    int height = 1;
    public:
        Rectangle():Shape(){}
        Rectangle(int serial, int w, int h):Shape(serial){
            setWidth(w);
            setHeight(h);
        }
        void setWidth(int w){
            this->width = w;
        }
        void setHeight(int h){
            this->height = h;
        }
        int getWidth(){
            return this->width;
        }
        int getHeight(){
            return this->height;
        }
        virtual void displayInfo(){
            cout << getSerialNumber() << endl;
            for(int i = 0; i < getHeight(); i++){
                for(int j = 0; j < getWidth(); j++){
                    cout << " * ";
                }
                cout << "\n";
            }
        }
};

class Spray : public Circle{
    int density = 1;
    public:
        Spray():Circle(){}
        Spray(int serial, int r, int d):Circle(serial, r){
            setDensity(d);
        }
        void setDensity(int dens){
            this->density = dens;
        }
        int getDensity(){
            return this->density;
        }
        virtual void displayInfo(){
            cout << getSerialNumber() << endl;
            srand(time(0));
            for(int i = -getRadius(); i <= getRadius(); i++){
                for(int j = -getRadius(); j <= 2 * getRadius(); j++){
                    if((int) sqrt(pow(i, 2) + pow(j, 2)) <= getRadius()){
                        if(rand() % 100 + 1 < getDensity())
                            cout << " * ";
                        else
                            cout << "   ";
                    }
                    else{
                        cout << "  ";
                    }
                }
                cout << "\n";
            }
        }
};

class Square : public Rectangle{
    public:
        Square():Rectangle(){}
        Square(int serial, int s):Rectangle(serial, s, s){}
        void setSide(int s){
            setWidth(s);
            setHeight(s);
        }
        int getSide(){
            return getWidth();
        }
        virtual void displayInfo(){
            cout << getSerialNumber() << endl;
            for(int i = 0; i < getSide(); i++){
                for(int j = 0; j < getSide(); j++){
                    cout << " * ";
                }
                cout << "\n";
            }
        }
};

const int SIZE = 5;

class shapeManager{
    Shape *arrShape[SIZE] = {nullptr};
    public:
        shapeManager(){
            ifstream inputFile;
            inputFile.open("shaperecords.txt", ios::in);
            if(inputFile.is_open()){
                int i = 0, serial = 0, dim1 = 0, dim2 = 0;
                char type;
                while(!inputFile.eof()){
                    inputFile >> type >> serial >> dim1 >> dim2;
                    switch(type){
                        case 'C':
                            arrShape[i] = new Circle(serial, dim1);
                            break;
                        case 'R':
                            arrShape[i] = new Rectangle(serial, dim1, dim2);
                            break;
                        case 'S':
                            arrShape[i] = new Spray(serial, dim1, dim2);
                            break;
                        case 'Q':
                            arrShape[i] = new Square(serial, dim1);
                            break;
                    }
                    i++;
                }
            }
        }
        ~shapeManager(){
            for(int i = 0; i < SIZE; i++){
                //create temp pointer copy
                Shape *ptr = arrShape[i];
                //delete the pointer
                delete ptr;
            }
        }
        void displayAll(){
            for(int i = 0; i < SIZE; i++){
                arrShape[i]->displayInfo();
            }
        }
};

int main(){
    shapeManager sm;
    sm.displayAll();
    return 0;
}