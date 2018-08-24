#include "./../../../Include/Common.h"

int count_paths(int rows, int cols)
{
    vector<vector<int>> dp; 
    
    // create a vector with cols elements 
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