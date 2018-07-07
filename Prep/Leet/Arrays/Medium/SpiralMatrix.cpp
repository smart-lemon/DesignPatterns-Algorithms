#include "./../../../../Include/Common.h"

using namespace std;

 // https://leetcode.com/problems/spiral-matrix/

class Solution {
    enum direction { 
        RIGHT = 0, 
        DOWN, 
        LEFT, 
        UP
    };
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int arrows[][2] {
                            0,  1, 
                            1,  0,
                            0, -1,
                           -1,  0
                        };
        vector<int> output; 
        direction dir = RIGHT;
        int layer = 0; 
        
        int R = matrix.size(); 
        int C = matrix[0].size();
        int len = R * C; 
        int i = 0, j = 0;
        
        if(R == 0 && C == 0)
            return output;
        
        cout << R <<  " " << C << endl;
        
        while(((i + 1)*(j + 1)) < len){
            //cout << "Layer "<< layer << " i " << i << " j " << j << endl;
            
            dir = RIGHT; 
            while(j < (C - layer - 1)) {
               // cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                output.push_back(matrix[i][j]);
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            
            dir = DOWN;
            while(i < R - layer - 1) {                
                
               // cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                output.push_back(matrix[i][j]);
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            dir = LEFT;
            
            while(j > layer) {
                output.push_back(matrix[i][j]);
                //cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            
            dir = UP;
            while(i > layer) {
                output.push_back(matrix[i][j]);
               // cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            
            if(i == layer && j == layer)
            {
                i++; 
                j++;
                layer++;
            }
        }
        return output;
    }
};