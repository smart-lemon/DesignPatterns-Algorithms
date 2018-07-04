
#include "./../../../../Include/Common.h"
using namespace std;

// https://leetcode.com/problems/valid-sudoku

class Solution {
    
    bool isUnique(vector<char> list){
        if(list.size() == 0)
            return true;
        sort (list.begin(), list.end());
        cout << endl << list[0] << " ";
        if(list.size() >= 1){
            for(int i = 1; i < list.size(); i++){
                cout << list[i] << " ";
                if(list[i - 1] == list[i])
                    return false;
            }
        } 
        
        return true;    
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> search; 

        // Check rows
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                 if(board[i][j] != '.'){
                     search.push_back(board[i][j]);
                 }
            }
            if(!isUnique(search))
                return false;
            search.clear();
        }
        

       // Check cols
       for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                 if(board[j][i] != '.'){
                     search.push_back(board[j][i]);
                 }
            }
            if(!isUnique(search))
                return false;
            search.clear();
        }
        
        for(int l = 0; l < board.size(); l += 3){
            for(int k = 0; k < board.size(); k += 3){
                search.clear();
                for(int i = 0 + k; i < ((board.size()/3) + k); i++){
                    for(int j = 0 + l; j < board[i].size()/3 + l; j++){
                        if(board[i][j] != '.'){
                            search.push_back(board[i][j]);
                        }
                    }
                }
                if(!isUnique(search))
                    return false;
            }
        }
        return true;
    }
};