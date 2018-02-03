#include "./../../Include/CommonInc.h"

using namespace std;

// Insertion sort is a simple sorting algorithm that works the way 
// we sort playing cards in our hands
void insertionsort(int *data, int n){

    for(int i = 1; i < n; i++){
        int j = i - 1;
        int key = data[i];
        
        //  Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while(j >= 0 && data[j] > key){
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void testInsertionSort()
{
    int dataset[] = {4, 2, 8, 0, 6, 7, 1, 3, 5, 9};
    int n = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Insertion sort of : ";
    print1DArray(dataset, n);

    insertionsort(dataset, n);

    cout << "Output : ";

    print1DArray(dataset, n);
}