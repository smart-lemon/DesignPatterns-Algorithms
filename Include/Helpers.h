#include "Common.h"


// ################ HELPER FUNCTIONS ################ //


void print2dArray(int **arr, int r, int c){
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void print2dArray(vector<vector<int>>& arr, int r, int c){
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}