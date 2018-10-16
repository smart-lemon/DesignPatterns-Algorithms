#include "./../../Include/Common.h"

/*
    387. First Unique Character in a String

    https://leetcode.com/problems/minimum-index-sum-of-two-lists/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap; 
        int ret = -1; 
        // build a histogram 
        for(char c: s){
            hashmap[c]++; 
        }
       
        // First occurence of the char with one occurence
        for(int i = 0; i < s.length(); i++){
            if(hashmap[s[i]] == 1){
                return i;
            } 
        }
        return ret;         
    }
};