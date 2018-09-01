#include "./../../../../Include/Common.h"

/*
    https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
   
        int n = 0, m = matrix.size();      
        
        if(m > 0)
            n = matrix[0].size();
        
        if(m == 0 || n == 0)
            return false;
        
        for(int i = 0; i < m && target >= matrix[i][0]; i++) {
            // Note : high should be the actual size (not n - 1)
            int low = 0, high = n; 
            int mid = 0;

            while(low < high) {
                
                mid = (low + high)/2; 

                if(target == matrix[i][mid]){
                    // found
                    return true;  
                } else if(target > matrix[i][mid]){
                    // search in higer quardrant
                    low = mid + 1;
                } else {                   
                    // search in lower quardrant
                    high = mid; 
                }
            }
        }
        return false; 
    }
};