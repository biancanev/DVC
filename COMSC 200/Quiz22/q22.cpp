#include <iostream>
#include <cstring>

using namespace std;

void reverseC_String(char *);
void reverseCpp_String(string &);

const int SIZE = 5;

int main(){
    char test[SIZE] = "EVIL";
    string test2 = "EVIL";
    cout << "C String: Before reverse, should output EVIL:\n" << test << endl;
    reverseC_String(test);
    cout << "C String: After reverse, should output LIVE:\n" << test << endl;
    cout << "C++ String: Before reverse, should output EVIL:\n" << test2 << endl;
    reverseCpp_String(test2);
    cout << "C++ String: After reverse, should output LIVE:\n" << test2 << endl;
}

void reverseC_String(char * cStr){
    //make a tempoary array that is the length of the string plus the null terminator
    char temp[SIZE];
    //iterate through the length of the cStr, i goes len->0, j goes 0->len
    for(int i = SIZE - 2, j = 0; i >= 0; i--, j++){
        //assign the descending cStr char as the ascending temp char
        temp[j]  = cStr[i];
    }
    //add the null terminator
    temp[SIZE] = 0;
    //redefine cStr
    strcpy(cStr, temp);
}

void reverseCpp_String(string & str){
    string temp;
    for(int i = str.length() - 1; i >= 0; i--){
        temp += str.at(i);
    }
    str = temp;
}