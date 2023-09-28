#include <iostream>

using namespace std;

string cleanString(const string);

int main(){
    cout << cleanString("          Token            Token      ") << endl;
}

string cleanString(string substring){
    string cleanedString = "";
    int i = substring.find(' '), j = substring.find_first_not_of(' ');
    substring.erase(i, j);
    //Step 2: Clear all trailing spaces
    i = substring.find_last_not_of(' ') + 1, j = substring.find_last_of(' ');
    substring.erase(i, j);
    //Step 3: Clear any extra spaces between words
    bool space = false;
    for(char c : substring){
        if(space){
            if(c != ' '){
                space = !space;
                cleanedString += c;
            }
        }else{
            if(c == ' '){
                space = !space;
            }
            cleanedString += c;
        }
    }
    return cleanedString;
}