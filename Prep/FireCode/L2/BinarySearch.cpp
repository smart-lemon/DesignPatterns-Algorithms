// namespace std have been included for this problem.
#include "./../../../Include/Common.h"
using namespace std;


// Add any helper functions(if needed) above.
bool binary_search(int arr[], int size, int n)
{
    // Add your code below this line. Do not modify any other code.  
    int low = 0, high = size, mid = 0; 
    
    while (low <  high) {
        
        mid = (low + high)/2; 
        
        if(arr[mid] == n)
            return true; 
        if(arr[mid] < n){
            low = mid + 1; 
        } else {
             high = mid;
        }
    }
    return false; 
    // Add your code above this line. Do not modify any other code.
}