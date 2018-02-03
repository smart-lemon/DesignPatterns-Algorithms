#include "./../Include/CommonInc.h"

using namespace std;


void print1DArray(int *arr, int n){

// For every item
	for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// swap position a with b 
void swap(int *numbers, int a, int b){
    int temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}