#include "./../../../../Include/Common.h"

/*
    454. 4Sum II

    Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
    there are such that A[i] + B[j] + C[k] + D[l] is zero.

    https://leetcode.com/problems/4sum-ii/
*/



class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hashmapAB;

        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                hashmapAB[A[i] + B[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                auto it = hashmapAB.find(0 - C[i] - D[j]);
                if(it != hashmapAB.end()) {
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};