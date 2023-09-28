#include <iostream> 
using namespace std; 
class  A 
{ 
protected: 
    int A_Var; 
public: 
    A(int val = 10) 
    { 
        A_Var = val; 
        cout << "A constructor: A_Var = " << A_Var << endl; 
    } 
    int getVar() 
    { 
        cout << "A::getVar = "; 
        return A_Var; 
    } 
}; 
 
class B: public A  // Change public to protected or private and see what can happen 
{ 
    private: 
        int B_Var; 
    public: 
        B(int val = 100) 
        { 
            B_Var = val; 
            cout << "B constructor: B_Var = " << B_Var << endl; 
        } 
        int getVar() 
        { 
            cout << "B::getVar = "; 
            return B_Var; 
        } 
}; 
 
int main() 
{ 
 
    cout  << endl << "\\1\\" << endl; 
    B bObj; 
 
    cout <<  endl << "\\2\\" << endl; 
    cout << bObj.getVar()<< endl; 
 
    cout  << endl << "\\3\\" << endl; 
    B *bPtr = nullptr; 
    bPtr = &bObj; 
    cout << bPtr->getVar() << endl; 
 
    cout  << endl << "\\4\\" << endl; 
    A *aPtr = nullptr; 
    aPtr = &bObj; 
    cout << aPtr->getVar() << endl; 
 
    return 0; 
}