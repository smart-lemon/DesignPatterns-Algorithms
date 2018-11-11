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

s
/*
    Space optimized for O(k)
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for(int i = 2; i <= rowIndex; i++){
            for(int j = i - 1; j >= 1; j--){
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};
