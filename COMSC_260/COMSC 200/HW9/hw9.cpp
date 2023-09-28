/****
 * 
 * In Object Oriented Analyysis and Design(OOAD), software developers often have to design classes with interfacability in mind. This is why
 * friend functions and classes can be so useful. It allows developer to access different member functions from different classes
 * without having to go through normal roundabout encapsulation methods. Once the interface has been established. The developer
 * car reestablish encapsulation by using getter and setter methods.
 * 
 * 
 *****/

#include <iostream>

using namespace std;

class Rectangle {
    private:
        int width, height;
    public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {
        if(width <= 0)
            width = 1;
        if (height <= 0)
            height = 1;
    }
    int area(){
        return width * height;
    }
    void doubleIt(){
        width *= 2;
        height *= 2;
    }
    Rectangle* tenTime(){
        width *= 10;
        height *= 10;
    }
};

int main ()
{
    Rectangle bar (2,3);
    cout << "Before: " << bar.area() << '\n';

    bar.doubleIt();
    cout << "After: " << bar.area() << '\n';

    Rectangle foo(-1,3);  /// Invalid data
    cout << "foo Before: " << foo.area() << '\n';  /// Should display 3

    foo.tenTime();
    cout << "foo After: " << foo.area() << '\n';

   return 0;
}