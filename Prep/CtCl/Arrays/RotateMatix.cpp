#include "./../../../Include/Common.h"

/*
    Rotate a matrix clockwise.
*/

void rotate_clockwise(int **matrix, int n) {
     
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