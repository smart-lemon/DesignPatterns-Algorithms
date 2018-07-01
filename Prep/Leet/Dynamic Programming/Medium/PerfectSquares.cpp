class Solution {
public:
    int numSquares(int n) {
        vector<int> squares; 
        for(int i = 0; i < n; i++)
            if(i*i > n)
                break;
            else 
                squares.push_back(i*i);
        
        vector<vector<int>> DP;
        
};