#include "./../../Include/CommonInc.h"

using namespace std;

void bubblesort(int *data, int n){

   bool swapped = true;

   // no more passes required if swapped remains false
   for(int pass = n - 1; pass >= 0 && swapped; pass--){

       swapped = false;
       for(int i = 0; i <= pass - 1 ; i++)
       {
           if(data[i] > data[i + 1]){
              swap(data, i, i + 1);
              swapped = true; 
           }
       }
   }
}

void testBubbleSort()
{
    int dataset[] = {4, 2, 8, 0, 6, 7, 1, 3, 5, 9};
    int n = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Bubble sort of : ";
    print1DArray(dataset, n);

    bubblesort(dataset, n);
    cout << "Output : ";

    print1DArray(dataset, n);
}