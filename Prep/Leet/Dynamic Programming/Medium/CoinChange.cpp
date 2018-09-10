
#include "./../../../../Include/Common.h"

/* 
    322. Coin Change - You are given coins of different denominations and a total amount of money amount. 
    Write a function to compute the fewest number of coins that you need to make up that amount.
    
    https://leetcode.com/problems/coin-change/
*/ 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) 
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};