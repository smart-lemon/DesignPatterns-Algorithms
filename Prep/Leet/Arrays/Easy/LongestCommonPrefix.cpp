#include "./../../../../Include/Common.h"

/* 
    14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.

    https://leetcode.com/problems/longest-common-prefix
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int mini = INT_MAX;
        
        // Find the smallest string len
        int number_of_words = strs.size();
        if(number_of_words == 0)
            return "";
        
        for(int list = 0; list < number_of_words; list++){
            mini = min(mini, (int) strs[list].size());
        }

        string res = "";
        // Compare the prefixes
        for(int i = 0; i < mini; i++){
            char current = strs[0][i];
            int j;
            for(j = 0; j < strs.size(); j++){
                if(strs[j][i] != current)
                    return res;
            }
            if(j == strs.size()){
                res += current;
            }
        }
        return res;
    }
};