#include "./../../Include/Common.h"

/* 
    49. Group Anagrams
    
    https://leetcode.com/problems/group-anagrams/description/ 
*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap; 
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i]; 
            sort(key.begin(), key.end());
            hashmap[key].push_back(strs[i]);
        }
        vector<vector<string>> res; 
        for(auto items : hashmap){
            res.push_back(items.second);
        }
        return res;
    }
};