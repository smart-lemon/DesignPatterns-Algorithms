#include "./../../../../Include/Common.h"

/*
   If an element is 0, set its entire row and column to 0. Do it in-place.
   
 
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        if(r > 1 && c > 1) {
            for(int i = 1; i < r; i++){
                for(int j = 1; j < c; j++){
                    if(matrix[i][j] == 0){
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }

        for(int i = 1; i < r; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < c; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 1; j < c; j++){
            if(matrix[0][j] == 0){
                 for(int i = 0; i < r; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};