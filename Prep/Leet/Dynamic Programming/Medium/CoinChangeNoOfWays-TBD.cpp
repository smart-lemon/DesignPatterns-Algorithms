#include "./../../../../Include/Common.h"


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> vec(ROW_NUMBER, vector <int> (COL_NUMBER, DEFAULT_VALUE))  
        
        if(coins.size() == 0 && amount == 0)
            return 1;
        else if(coins.size() == 0)
            return 0;

        int cols = amount + 1, rows = coins.size();
        vector<vector<int>> dp(rows, vector <int>(cols, 0));

        // There is one way to make the amount 0, using no coins
        for(int r = 0; r < rows; r++)
            dp[r][0] = 1;
        
        int top = 0, left = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 1; c < cols; c++){
                top = 0, left = 0;
                if(r - 1 >= 0) 
                    top = dp[r - 1][c]; 
                if(c - coins[r] >= 0){
                    left = dp[r][c - coins[r]]; 
                }
                dp[r][c] = top + left ;
            }
        }
        return dp[rows - 1][cols - 1];
    }
};