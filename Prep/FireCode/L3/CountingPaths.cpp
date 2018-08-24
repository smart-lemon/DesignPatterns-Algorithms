
/*
    You're given a game board that has m x n squares on it, represented by an m x n array. 
    Write a method - count_paths that takes in m and n and returns the number of possible paths 
    from the top left corner to the bottom right corner. Only down and right directions of movement 
    are permitted. 
*/

int max(int a, int b){
    return a > b? a : b;
}

int count_paths(int rows, int cols)
{
    int **dp; 
    dp = new int*[cols];

    for(int i = 0; i < cols; i++){ 
        dp[i] = new int[rows];
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < cols; i++){ 
        for(int j = 0; j < rows; j++){
            if(i - 1 >= 0 && j - 1 >= 0){
                dp[i][j] = dp[i - 1][j] + 1 + dp[i][j - 1] + 1;
            }
        }
    }

    return dp[rows - 1][cols - 1];
}