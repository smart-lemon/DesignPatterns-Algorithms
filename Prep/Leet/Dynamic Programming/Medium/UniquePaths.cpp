#include "./../../../../Include/Common.h"

/*
    https://leetcode.com/problems/unique-paths/description/
*/

class Solution {
  
    int uniquePaths(int rows, int cols) {
        vector<vector<int>> dp; 
        vector<int> row(cols, 1); 
    
        for(int i = 0; i < rows; i++)
            dp.push_back(row); 
    
        for(int i = 1; i < rows; i++)
        {
            for( int j = 1; j < cols; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    
        return dp[rows - 1][cols - 1];
    }

    int uniquePathsLesserSpace(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }

}; 