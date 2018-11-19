#include "./../../../../Include/Common.h"

/*
    Number of Islands : Given a 2d grid map of '1's (land) and '0's (water), 
    count the number of islands

    
*/
nt dirs [][2] = {
            {0,  1},
            {1,  0},
            {-1, 0}, 
            {0, -1}
        };
class Solution {
    vector<vector<char>> visited;
    int islands;
    queue<pair<int, int>> q;
        
       
    public:
    bool check_boundary(int i, int j, int r, int c){
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size();
        islands = 0;

        if(r == 0)
            return islands;
        int c = grid[0].size();

        // Allocate visited
        visited.resize(r, vector<char>(c, 0));

        // For every unvisited pixel in the map do a bfs
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid, i, j, r, c);
                }
            }
        }
        return islands;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, int r, int c){        
        
        islands++;
        q.push(make_pair(i, j));

        while(q.size()){
            pair<int, int> location = q.front();
            visited[location.first][location.second] = 1; 
            q.pop();
            int new_r = 0, new_c = 0;
            for(int k = 0; k < 4; k++){
                new_r = location.first  + dirs[k][0];
                new_c = location.second + dirs[k][1];
                if( check_boundary(new_r, new_c, r, c) && 
                    grid[new_r][new_c] == '1' && !visited[new_r][new_c]){
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