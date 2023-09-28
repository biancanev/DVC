#include <iostream>
#include <map>
#include <fstream>

using namespace std;

map<string, int> wordCount;

string toLowerCase(string word);

int main(){
    fstream inputFile;
    string word;
    inputFile.open("NotesBetweenTwoSisters.txt", ios::in);
    if(inputFile.good()){
        while(inputFile >> word){
            string lower = toLowerCase(word);
            if((wordCount.find(lower) != wordCount.end())){
                wordCount[lower]++;
            }else if(lower != ""){
                wordCount[lower] = 1;
            }
        }
    }
    cout << "Word      Instances" << endl;
    cout << "-------------------" << endl;
    for(map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it){
        cout.width(9);
        cout << it->first;
        cout.width(10);
        cout << it->second << endl;
    }
}

string toLowerCase(string word){
    string newWord = "";
    int i = 0;
    while(word[i]){
        if(ispunct(word[i]) != 0){
            if(i != 0 && i != word.length() - 1){
                return "";
            }
        }else{
            newWord += tolower(word[i]);
        }
        i++;
    }
    return newWord;
}