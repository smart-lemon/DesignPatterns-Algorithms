#include "./../../../../Include/Common.h"

/*
    
     https://leetcode.com/problems/perfect-squares/
*/

class Solution {
    
    int min(int a, int b){
        return a < b? a : b;
    }
public:
    int numSquares(int n) {
        vector<int> squares;
        
        if(n <= 1)
            return n;
        for(int i = 1; i < n; i++) {
            if(i*i > n)
                break;
            else {                
                squares.push_back(i*i);
            }
        }
        
        vector<int> DP(n + 1, 0);
        DP[0] = 0; 
        DP[1] = squares[0];
        
        for(int i = 2; i <= n; i++) {
            int minOf = INT_MAX; 
            for(int j = 0; j < squares.size(); j++) {
                if(i - squares[j] >= 0){
                    minOf = min(DP[i - squares[j]] + 1, minOf); 
                }
            }
            DP[i] = minOf;
        }
        return DP[n];
    }
};