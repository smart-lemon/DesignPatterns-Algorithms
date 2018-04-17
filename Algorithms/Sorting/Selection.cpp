#include "./../../Include/Common.h"

using namespace std;

/*
    Selection sort
*/

void selection_sort(int *data, int n){

   int min;
   for(int i = 0; i < n - 1; i++){
       min = i;
       // Find the minimum value in the list
       for(int j = i + 1; j < n ; j++)
       {
           if(data[j] < data[min]){
              min = j;
           }
       }
       // Swap it with current position 
       swap(data, min, i);
   }
}


void testSelectionSort()
{
    int dataset[] = {4, 2, 8, 0, 6, 7, 1, 3, 5, 9};
    int n = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Selection sort of : ";
    print1DArray(dataset, n);

    selection_sort(dataset, n);

    cout << "Output : ";

    print1DArray(dataset, n);
}