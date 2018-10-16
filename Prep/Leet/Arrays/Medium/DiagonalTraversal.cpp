#include "./../../../../Include/Common.h"

/* 
    498. Diagonal traversal 
    https://leetcode.com/problems/diagonal-traverse/ 
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
                r++; c--; // Compenstaion for overshooting
                
                // Move right if c < C - 1 else move down 
                (c < C - 1) ? c++ : r++;
            } else {
                while(boundsCheck(r, c, R, C)){
                    // Slide down diagonally                   
                    ans.push_back(matrix[r][c]); 
                    r++;
                    c--;
                }
                r--; c++; // // Compenstaion for overshooting

                // Move down if r < R - 1 else move right 
                (r < R - 1) ? r++ : c++;
            }
            // Change directions
            direction == UP? direction = DOWN : direction = UP;
        }
        return ans;
    }
    
    
    vector<int> findDiagonalOrderAlternative(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>();
        int n = matrix[0].size();
        
        // Number of diagonals are m + n - 1
        vector<vector<int>> tmp (m + n - 1);
        
        // Put all diagonal sequences from top-right to bottom-left to an array
        for (int i = 0; i < m + n - 1 ; i++) {
            int row = max(0, i - n + 1);
            int col = min(i, n - 1);
            for (; col >= 0 && row < m; row++, col--) {
                tmp[i].push_back(matrix[row][col]);
            }
        }

        // Combine all sequence together by reversing odd sequences.
        vector<int> res;
        for (int i = 0; i < tmp.size(); i++) {
            if (i % 2) 
                res.insert(res.end(), tmp[i].begin(), tmp[i].end());
            else 
                res.insert(res.end(), tmp[i].rbegin(), tmp[i].rend());
        }

        return res;
    }
};