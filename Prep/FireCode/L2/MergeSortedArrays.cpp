// namespace std have been included for this problem.
#include "./../../../Include/Common.h"
using namespace std;

// Add any helper functions(if needed) above.
int* merge(int arr_left[],int sz_left, int arr_right[], int sz_right){
    /* declaring an array using dynamic allocation of memory. 
        Merged the given two arrays into this third output Array */
    int* arr_merged = new int [sz_left+sz_right];
    // Add your code below this line. Do not modify any other code.
    int k = 0, r = 0, l = 0;
    while(k < sz_left + sz_right){
        
          if(arr_right[r] < arr_left[l] && r < sz_right)
          { 
              arr_merged[k] = arr_right[r];
              r++;
          } else if (arr_right[r] > arr_left[l] && l < sz_left){

              arr_merged[k] = arr_left[l];
              l++;
          } else if(arr_right[r] == arr_left[l] && r < sz_right && l < sz_left) {

              arr_merged[k] = arr_left[l];
              k++;
              arr_merged[k] = arr_right[r];
              r++; l++;
          }
          
          k++;
          
          if(r == sz_right  || l == sz_left )
             break;
    }
    
    while(r < sz_right){
        arr_merged[k] = arr_right[r];
        r++;
        k++;
    }
    
    while(l < sz_left){
         arr_merged[k] = arr_left[l];
         l++;
         k++;
    }
    
    // Add your code above this line. Do not modify any other code.
    /* return the merged array */
    return arr_merged;
}