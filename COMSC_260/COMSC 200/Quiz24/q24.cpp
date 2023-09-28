/**
 * Question: The getQuotient() function takes two integers or doubles as input and returns the quotient. 
 * Taking the getQuotient() as example, what may go wrong when using this template?
 * 
 * getQuotient() requires the user to input either 2 integers or doubless. However, it does not allow for
 * mixing fo 2 data types. For exaple if you wanted to divide 4.2 by 7, it would not work.
 * **/

#include <iostream>
#include <cstdlib>
#include "time.h"

using namespace std;

template <typename T>
T randomPick(T a, T b, T c){
    switch(rand() % 3 + 1){
        case 1:
            return a;
        case 2:
            return b;
        case 3:
            return c;
        default:
            cout << "Something went wrong. Returning a." << endl;
            return a;
    }
}

template <typename T2>
T2 getChoice(string s1, string s2, T2 o1, T2 o2){
    while(1){
        string answer;
        cout << "Please pick " << s1 << " or " << s2 << ":" << endl;
        getline(cin, answer);
        if(answer == s1){
            return o1;
        }
        if(answer == s2){
            return o2;
        }
        cout << "Invalid choice!" << endl;
    }
}

int main(){
    srand(time(NULL));

    cout << "Part 1" << endl;
    cout << randomPick('1','2','3') << endl;
    cout << randomPick (11,22,33) << endl;
    cout << randomPick ("Mac","PC","Others") << endl << endl;

    cout << "Part 2" << endl;
    cout << getChoice("x","y", 1, 2) << endl << endl;
    /// User enters z -> system fails to get a choice
    /// User enters y -> system returns 2
}