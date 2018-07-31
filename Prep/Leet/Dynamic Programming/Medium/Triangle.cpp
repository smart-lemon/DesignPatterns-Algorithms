#include "./../../../../Include/Common.h"

// https://leetcode.com/problems/triangle 

class Solution {
    
    int min(int a, int b){
        return a < b? a : b;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // Figure out the max dimensions of the arrays (R - Number of rows, C - Max Numbers of colums)
        int R = triangle.size(), C =  triangle[R - 1].size(); 
        
        for(int i = 1; i < R; i++) {
            for(int j = 0; j < triangle[i].size(); j++){
                if(j == 0){
                    // If on the first column, you have no choice but to select prev rows first element + current element
                    triangle[i][j] += triangle[i - 1][0];   
                } else if(j == triangle[i].size() - 1){
                    // Similarly for the last column you gotta pick up the previous rows last element. 
                    triangle[i][j] += triangle[i - 1][triangle[i - 1].size() - 1]; 
                } else {
                     // For the rest elements that dont lie on the boundary, it's the minimum of the adjacent element of prev rows
                     triangle[i][j] +=  min(triangle[i - 1][j - 1], triangle[i - 1][j]); 
                }
            }
        }
                
        int ans = INT_MAX; 
        for(int j = 0; j < C; j++) {
            ans = min(triangle[R - 1][j], ans); 
        }
        return ans;
    }
};