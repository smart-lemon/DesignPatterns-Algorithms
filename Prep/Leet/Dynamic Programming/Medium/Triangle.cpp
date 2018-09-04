#include "./../../../../Include/Common.h"

/*
    120. Triangle
    https://leetcode.com/problems/triangle 
*/

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

    int minimumTotalTerse(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n  -2; layer >= 0; layer--) // For each layer
        {
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i]; 
            }
        }
        return minlen[0];
    }
};