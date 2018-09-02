#include "./../../../../Include/Common.h"

/* 
    498. Diagonal traversal 
    https://leetcode.com/problems/diagonal-traverse/description/ 
*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int R = 0, C = 0;
        vector<int> ans; 

        enum dir {
            UP = true,
            DOWN = false
        };

        dir direction = UP;

        // The dimensions
        R = matrix.size();
        C = matrix[0].size();

        while(ans.size() == R * C) {
            
        }
    }
};