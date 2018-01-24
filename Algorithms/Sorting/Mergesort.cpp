#include "./../../Include/CommonInc.h"

using namespace std;





void testMergesort()
{
    int dataset[] = {102, 54, -19, 99, 0, 69};
    int low = 0, high = sizeof(dataset)  / sizeof(dataset[0]);

    cout << "Mergesort: ";
    print1DArray(dataset, high);
    
}