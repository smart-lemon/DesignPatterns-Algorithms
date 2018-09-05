#include "./../../../../Include/Common.h"

/*
    https://leetcode.com/problems/unique-paths-ii/description/
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp; 
        int cols = obstacleGrid[0].size(), rows = obstacleGrid.size();
        
        vector<int> row(cols, 1);  
        for(int i = 0; i < rows; i++)
            dp.push_back(row);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                // Marking an obstacle, note: opposite notation as input 
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
            }
        }           

        
        for(int i = 1; i < rows; i++)
        {
            for( int j = 1; j < cols; j++){
                int right = dp[i - 1][j]; 
                int top = dp[i][j - 1];
                if(dp[i][j] != 0)
                    dp[i][j] = top + right;
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};