#include "./../../../../Include/Common.h"

/* 
    498. Diagonal traversal 
    https://leetcode.com/problems/diagonal-traverse/description/ 
*/


class Solution {
public:
    enum dir {
            UP = true,
            DOWN = false
    };

    inline bool boundsCheck(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int R = 0, C = 0, r = 0, c = 0;
        vector<int> ans; 
        dir direction = UP;

        // The dimensions
        R = matrix.size();
        if(R == 0) return ans; 
        
        C = matrix[0].size();

        while(ans.size() < R * C) {
            
            if(direction == UP) {
                while(boundsCheck(r, c, R, C)){
                    // Slide up diagonally
                    ans.push_back(matrix[r][c]); 
                    r--;
                    c++;
                }
                // Shift right or down
                r++; // Compenstaion for r-- 
                c--;
                (c < C - 1) ? c++ : r++;
                
            } else {
                while(boundsCheck(r, c, R, C)){
                    // Slide down diagonally                   
                    ans.push_back(matrix[r][c]); 
                    r++;
                    c--;
                }
                // Shift right or down
                r--; c++;
                (r < R-1) ? r++ : c++;

            }

            direction == UP? direction = DOWN : direction = UP;
        }
        return ans;
    }
};