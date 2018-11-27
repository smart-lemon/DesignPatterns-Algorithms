#include "./../../../../Include/Common.h"

/*
    Rotate the image by 90 degrees (clockwise). In place. 

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();        
        if(n <= 1)
            return;
        
        // Layer by layer rotation
         for(int layer = 0; layer < n / 2; layer++) {
            int last = n - 1 - layer; 
            for(int i = layer; i < last; i++){
                int offset = i - layer; 
                int temp = matrix[layer][i];
                matrix[layer][i] = matrix[last - offset][layer]; 
                matrix[last - offset][layer] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = temp;
            }
        }
    }
};

/*

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/