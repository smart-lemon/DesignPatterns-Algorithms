#include <malloc.h>
/*
    2D array C allocation
*/

int ** allocate2dCArray(int r, int c){
    int **dp = (int **)malloc(r * sizeof(int *)); 
    for (int i = 0; i < r; i++) {
         dp[i] = (int *)malloc((c) * sizeof(int)); 
    }
    return dp;
}

/*
    2D array C++ allocation
*/
int **allocate2dCppArray(int r, int c){
    int **dp = new int*[r];
     for (int i = 0; i < r; i++) {
         dp[i] = new int[c]; 
    }
    return dp;
}

/*
    2D array STL allocation
*/
vector<vector<int>> allocate2dStl(int r, int c){
    vector<vector<int>> dp(r, vector <int>(c, 0))
    return dp;
}