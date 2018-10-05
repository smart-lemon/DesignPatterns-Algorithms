#include "./../../../Include/Common.h"

int max_sum_cont_sequence(int arr[], int sz)
{
    int max_current, max_overall;
    if(sz == 0)
        return 0;

    // 1. Define max_current and max_overall as the first element
    max_current = max_overall = arr[0];
    
    for(int i = 1; i < sz; i++) {
        // 2. The current local maximum can be the current element or 
        // the current local maximum including the current element
        max_current = max(arr[i], max_current + arr[i]); 

        // 3. Update the overall maximum with the best local maximum so far 
        if(max_current > max_overall)
            max_overall = max_current;
    }
    return max_overall;
    
}