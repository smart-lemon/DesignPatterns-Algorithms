#include "./../../../../Include/Common.h"

/*
    Number of Islands : Given a 2d grid map of '1's (land) and '0's (water), 
    count the number of islands

    
*/


class Solution {
    vector<vector<int>> visited;
    int islands;

public:

    bool check_boundary(int i, int j, int r, int c){
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size();
        islands = 0;
        if(r == 0)
            return r;

        int c = grid[0].size();

        // Allocate visited
        visited.resize(r, vector<int>(c, 0));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                if(!visited[i][j] && grid[i][j]){
                    bfs(grid, i, j, r, c);
                }
            }
        }
        return islands;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, int r, int c){
        int dirs [][2] = {
            {0,  1},
            {1,  0},
            {-1, 0}, 
            {0, -1}
        };
        islands++;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));

        while(q.size()){
            pair<int, int> location = q.front();
            visited[location.first][location.second] = 1; 
            q.pop();            
            int new_r = 0, new_c = 0;
            for(int k = 0; k < 4; k++){
                new_r = location.first + dirs[k][0];
                new_c = location.second + dirs[k][1];
                if( check_boundary(new_r, new_c, r, c) && 
                    grid[new_r][new_c] && !visited[new_r][new_c]){
                    q.push(make_pair(new_r, new_c));
                }
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