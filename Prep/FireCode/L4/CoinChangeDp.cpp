#include "./../../../Include/Common.h"

/*
    Given an array containing the available denominations of coins in descending order, 
    write a function to compute the number of possible ways of representing a monetary amount in cents. 
*/


int make_change(int coins[], int n, int amount){
    if(amount <= 0) 
        return 0;
    
    int **dp = new int*[n]; 
    
    for(int i = 0; i < n; i++){
        dp[i] = new int[amount + 1];
        dp[i][0] = 1;
    }
  
    for(int r = 0; r < n; r++){
        for(int c = 1 ; c <= amount; c++){
            
            int top = 0, left = 0; 
            if(c - coins[r] >= 0)
                left = dp[r][c - coins[r]];
            
            if(r-1 >= 0)
                top = dp[r - 1][c];
            dp[r][c] = top + left; 
        }
    }
    return dp[n - 1][amount];  
}