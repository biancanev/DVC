#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10; /// The maximum size of a C-string is 10

/// ADD FUNCTION PROTOTYPES HERE
bool isPalindomic(char*);
bool isSubstr(string, string);
void removeDuplicates(int **);

int main() {

    cout << "Part 1 *******" << endl << endl;

    char str1[SIZE] = "I";

    if (isPalindomic(str1))
        cout << str1 << " is palindromic." << endl << endl;
    else
        cout << str1 << " is not palindromic." << endl << endl;

    char str2[SIZE] = "RADAR";
    if (isPalindomic(str2))
        cout << str2 << " is palindromic." << endl << endl;
    else
        cout << str2 << " is not palindromic." << endl << endl;

    char str3[SIZE] = "ABCDEF";
    if (isPalindomic(str3))
        cout << str3 << " is palindromic." << endl;
    else
        cout << str3 << " is not palindromic." << endl;

 

    cout << "Part 2 *******" << endl << endl;

    string str4 = "abcdefg";
    string str5 = "a";
    string str6 = "fg";
    string str7 = "cef";

    if (isSubstr(str4, str5))
        cout << str5 << " is a sub-string of " << str4 <<"." << endl << endl;
    else
        cout << str5 << " is not a sub-string of " << str4 <<"." << endl << endl;

    if (isSubstr(str4, str6))
        cout << str6 << " is a sub-string of " << str4 <<"." << endl << endl;
    else
        cout << str6 << " is not a sub-string of " << str4 <<"." << endl << endl;

    if (isSubstr(str4, str7))
        cout << str7 << " is a sub-string of " << str4 <<"." << endl << endl;
    else
        cout << str7 << " is not a sub-string of " << str4 <<"." << endl<< endl;

    if (isSubstr(str4, str4))
        cout << str4 << " is a sub-string of " << str4 <<"." << endl << endl;
    else
        cout << str4 << " is not a sub-string of " << str4 <<"." << endl<< endl;

 

    cout << "Part 3 *******" << endl << endl;
    int **  arrInt1 = new int*[SIZE];
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        /// new int objects in the array
        arrInt1[i] = new int(rand()%4);
    }
    cout << "Before calling removeDuplicates()" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        /// Display the integers in the array before calling removeDuplicates()
        cout << *arrInt1[i] << ", ";
    }
    cout << endl;
    removeDuplicates(arrInt1);
     cout << "After calling removeDuplicates()" << endl;
     for (int i = 0; i < SIZE; i++)
    {
        /// Display the integers in the array after calling removeDuplicates()
        if(arrInt1[i])
            cout << *arrInt1[i] << ", ";
    }

    return 0;
}

bool isPalindomic(char *x){
    int end = SIZE - 1;
    //find the true "end" of the character array(last non-null character)
    while(x[end] == '\0'){
        end--;
    }
    //compare beginning and end and move towards each other until it reaches the middle(if even length middle is last 2 characters)
    for(int i = 0; end - i > 1; i++){
        if(x[i] != x[end]){
            return false;
        }
        end--;
    }
    return true;
}


bool isSubstr(string x, string y){
    for(int i = 0; i < x.length(); i++){
        //find where a potential substring starts
        if(x.at(i) == y.at(0)){
            //boolean to record if it really is a substring
            bool isSub = true;
            //iterate through length of y
            for(int j = 0; j < y.length(); j++){
                //if there is a discrepency
                if(x.at(i+j) != y.at(j)){
                    //change to not a substring
                    isSub = false;
                    //end the loop
                    break;
                }
            }
            //if the loop made it all the way through
            if(isSub){
                return true;
            }
        }
    }
    //if no matching characters were even found
    return false;
}


void removeDuplicates(int **arr){
    //bubble sort function
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(*arr[j] > *arr[i]){
                int *tempj = arr[j];
                arr[j] = arr[i];
                arr[i] = tempj;
            }
        }
    }
    int curr = *arr[0];
    //delete all duplicates
    for(int i = 1; i < SIZE; i++){
        if(*arr[i] == curr){
            delete arr[i];
            arr[i] = nullptr;
        }else{
            curr = *arr[i];
        }
    }
}