#include <iostream>
#include <vector>

using namespace std;
class Parser{
    private:
        vector<string> tokens;
    public:
        Parser(){}
        void parseString(string);
        string removeSpaces(string);
        void displayAll();
};

int main(){
    Parser prs;
    string str1 = " \"Royal  Caribbean    International \" \" Jurre Van Wouw\" 1987 \"For Sale\" ";
    string str2 = " \" Royal Caribbean   International   \" \" Jurre Van Wouw\" 1987 \"For Sale\" \\10\\02\\2009 ";
    string str3 = " \"      Royal Caribbean International    \" \" Jurre Van Wouw\" 1987 \" For Sale\" \\10\\02\\2009 925-123-2346 ";
    prs.parseString(str1);
    prs.parseString(str2);
    prs.parseString(str3);
    prs.displayAll();
}

void Parser::parseString(string searchString){
    while(!searchString.empty()){
        int i = searchString.find(' '), j = searchString.find('\"'), k, l;
        if(j == -1){
            j = i+2;
        }
        if(i == j - 1){
            if(searchString.length() == 1){
                tokens.push_back("\n\n");
                return;
            }
            l = searchString.find('\"', j + 1);
            tokens.push_back(removeSpaces(searchString.substr(j, l)));
            searchString.erase(i, l + 1);
        }else if(j < i){
            if(searchString.length() == 1){
                tokens.push_back("\n\n");
                return;
            }
            l = searchString.find('\"', j + 1);
            tokens.push_back(removeSpaces(searchString.substr(j, l)));
            searchString.erase(j, l);
        }else{
            if(searchString.length() == 1){
                tokens.push_back("\n\n");
                return;
            }
            k = searchString.find(' ', i + 1);
            tokens.push_back(searchString.substr(i + 1, k - 1)); 
            searchString.erase(i, k);
        }
    }
}

string Parser::removeSpaces(string substring){
    string cleanedString = "";
    //Step 1: Clear all leading spaces and quotes
    for(int a = substring.find('\"'); a != string::npos; a = substring.find('\"')){
        substring.erase(a, 1);
    }
    int i = substring.find(' '), j = substring.find_first_not_of(' ');
    substring.erase(i, j);
    //Step 2: Clear all trailing spaces and quotes
    i = substring.find_last_not_of(' ') + 1, j = substring.find(' ');
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

void Parser::displayAll(){
    for(string token : tokens){
        cout << token << endl;
    }
}