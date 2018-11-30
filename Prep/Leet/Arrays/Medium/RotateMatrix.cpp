#include "./../../../../Include/Common.h"


/*
    Rotate image by 90 degrees clockwise

    https://leetcode.com/problems/rotate-image/
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int layer = 0; layer < n / 2; layer++) {
            int last = n - 1 - layer; 

            // Rotate the matrix in place 
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

