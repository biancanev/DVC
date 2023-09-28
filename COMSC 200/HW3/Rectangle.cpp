#include "Rectangle.h"

//Rectangle class construtor
Rectangle::Rectangle(double w, double h){
    if(w <= 0 || w > 7){
        width = 9;
    }
    if(h <= 0 || h > 7){
        height = 9;
    }else{
        width = w;
        height = h;
    }
}

Rectangle::~Rectangle(){

}

void Rectangle::setWidth(double w){
    width = w;
}

void Rectangle::setHeight(double h){
    height = h;
}

void Rectangle::setSerialNumber(int ser){
    serialNumber = ser;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getHeight() const{
    return height;
}

int Rectangle::getSerialNumber() const{
    return serialNumber;
}

int Rectangle::numSquare = 0;
int Rectangle::numVert = 0;
int Rectangle::numHoriz = 0;

void Rectangle::incrementHoriz(){
    numHoriz++;
}

void Rectangle::incrementVert(){
    numVert++;
}

void Rectangle::incrementSquare(){
    numSquare++;
}

int Rectangle::getHorizCount(){
    return numHoriz;
}
int Rectangle::getVertCount(){
    return numVert;
}
int Rectangle::getSquareCount(){
    return numSquare;
}