#include "./../../Include/Common.h"

using namespace std;



void testHeapSort()
{
    int dataset[] = {4, 2, 8, 0, 6, 7, 1, 3, 5, 9};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Bubble sort of : ";
    print1DArray(dataset, high);

    int *output = new int[high];
    
    cout << "Output : ";

    print1DArray(output, high);
}