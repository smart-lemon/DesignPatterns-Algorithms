#include "./../../../../Include/Common.h"

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
        if(R == 0)
            return output;
        int C = matrix[0].size();
        int len = R * C; 
        int i = 0, j = 0;
        
        cout << R <<  " " << C << endl;
        
        if(R == 1 && C == 1)
            output.push_back(matrix[i][j]);
        
        while(output.size() < len){
            cout << "Layer "<< layer << " i " << i << " j " << j << endl;
            
            dir = RIGHT; 
            while(j < (C - layer - 1) && output.size() < len) {
                cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                output.push_back(matrix[i][j]);
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            
            dir = DOWN;
            while(i < R - layer - 1 && output.size() < len) {                
                
                cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                output.push_back(matrix[i][j]);
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            dir = LEFT;
            
            while(j > layer && output.size() < len) {
                output.push_back(matrix[i][j]);
                cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            
            dir = UP;
            while(i > layer && output.size() < len) {
                output.push_back(matrix[i][j]);
                cout << i << ","<< j << " -> "<< matrix[i][j] << endl;
                i = i + arrows[dir][0];
                j = j + arrows[dir][1];
            }
            
            if(i == layer && j == layer)
            {
                i++; 
                j++;
                layer++;
                cout << "New layer"  << endl;
                if(i >= 0 && i >= 0 && i < R && j < C)
                    output.push_back(matrix[i][j]);
            }
        }
        return output;
    }
};