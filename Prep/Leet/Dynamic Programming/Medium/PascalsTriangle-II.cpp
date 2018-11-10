#include "./../../../../Include/Common.h"


/*
    118. Pascal's Triangle - get the last row
    
    https://leetcode.com/problems/pascals-triangle/
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex + 1);

        for(int i = 0; i <= rowIndex; i++){
            result[i].resize(i + 1);
            result[i][0] = result[i][i] = 1;

            for(int j = 1; j < i; j++) 
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        
        return result[rowIndex]; 
    }
};


#include "./../../../../Include/Common.h"


/*
    Space optimized for O(k)
*/
