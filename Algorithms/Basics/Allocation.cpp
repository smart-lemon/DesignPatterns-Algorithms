#include <malloc.h>
/*
    2D array C allocation
*/
static int r = 10, c = 20;

void allocate2dCArray(){
    int **dp = (int **)malloc(r * sizeof(int *)); 
    for (int i = 0; i < r; i++) {
         dp[i] = (int *)malloc((c) * sizeof(int)); 
    }
    
}

void allocate2dCppArray(){
    int **dp = new int*[r];
     for (int i = 0; i < r; i++) {
         dp[i] = new int[c]; 
    }
}

void allocate2dStl(){
    vector<vector<int>> dp(r, vector <int>(c, 0));
}