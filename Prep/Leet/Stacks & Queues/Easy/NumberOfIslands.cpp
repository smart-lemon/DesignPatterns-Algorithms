#include "./../../../../Include/Common.h"

/*
    Number of Islands : Given a 2d grid map of '1's (land) and '0's (water), 
    count the number of islands

    https://leetcode.com/problems/number-of-islands/
*/

int dirs [][2] = {
            {0,  1},
            {1,  0},
            {-1, 0}, 
            {0, -1}
        };

class Solution {
    int islands; 
       
    public:
    inline bool check_boundary(int i, int j, int r, int c){
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size();
        islands = 0;

        if(r == 0)
            return islands;
        int c = grid[0].size();

        bool doBfs = true;

        // Do BFS 
        if(doBfs) {
            // For every unvisited pixel in the map do a bfs
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++){
                    if(grid[i][j] == '1'){
                        islands++;
                        bfs(grid, i, j, r, c);
                    }
                }
            }
        } else {
            // Do DFS        
            vector<vector<bool>> visited(r, vector<bool> (c, false));

              for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        islands++;
                        dfs(grid, visited, i, j, r, c);
                    }
                }
            }
        }        
        return islands;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, int r, int c){        
        
        queue<pair<int, int>> q;       
        q.push(make_pair(i, j));

        while(!q.empty()){
            pair<int, int> location = q.front();
            q.pop();
            int new_r = 0, new_c = 0;
            for(int k = 0; k < 4; k++){
                new_r = location.first  + dirs[k][0];
                new_c = location.second + dirs[k][1];
                if( check_boundary(new_r, new_c, r, c) && 
                    grid[new_r][new_c] == '1' ){                    
                    // Instead of visited, modify the grid
                    grid[new_r][new_c] = '0';
                    q.push(make_pair(new_r, new_c));
                }
            }
        }
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int r, int c) {
        visited[i][j] = true;
        int new_r = 0, new_c = 0;
        for(int k = 0; k < 4; k++){
            new_r = i + dirs[k][0];
            new_c = j + dirs[k][1];

            if ( check_boundary(new_r, new_c, r, c) && 
                 grid[new_r][new_c] == '1' && !visited[new_r][new_c]){
                    dfs(grid, visited, new_r, new_c, r, c);
            }
        }
    }
};



/*

Input:
    11110
    11010
    11000
    00000

Output: 1

Input:
    11000
    11000
    00100
    00011

Output: 3

*/