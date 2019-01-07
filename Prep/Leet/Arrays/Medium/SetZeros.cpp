#include "./../../../../Include/Common.h"

/*
   If an element is 0, set its entire row and column to 0. Do it in-place. 
 
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        bool first_row_has_zero = false, first_col_has_zero = false; 

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){

                    matrix[0][j] = 0;
                    matrix[i][0] = 0;

                    if(i == 0)
                        first_row_has_zero = true;
                    if(j == 0)
                        first_col_has_zero = true;    
                }
            }
        }

        // Here is the main logic. If the rows or columns are marked as zero make i,j as zero 
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0) 
                    matrix[i][j] = 0;
            }
        }

       
        if(first_row_has_zero){
            for(int j = 0; j < matrix[0].size(); j++) 
                matrix[0][j] = 0;
        } 
        if(first_col_has_zero){
            for(int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
    }
};