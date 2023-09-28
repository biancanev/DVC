#include <iostream>

using namespace std;

void displayArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int arr [4] = {1, 2, 3, 4};
    displayArr(arr, 4);
}