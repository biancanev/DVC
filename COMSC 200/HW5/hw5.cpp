#include "myVector.h"

int main(){
    myVector <int> myVect;

    myVect.push_back(1);
    myVect.push_back(3);
    myVect.push_back(5);
    myVect.display();

    myVect.pop_back();
    myVect.display();

    myVector <string>  myVect2;
    myVect2.push_back("This ");
    myVect2.push_back("is ");
    myVect2.push_back("my ");
    myVect2.push_back("day. ");
    myVect2.display();

    cout << "AT: " << myVect2.at(3) << endl;
    cout << "INDEX: " << myVect2.indexOf("This ") << endl;
    myVect2.pop_back();
    myVect2.display();
    return 0;
}
