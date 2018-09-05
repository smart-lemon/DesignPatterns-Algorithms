#include "./../../../../Include/Common.h"

/*
    205. Isomorphic Strings
    https://leetcode.com/problems/isomorphic-strings/description/
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    string input1 = s, input2 = t;
    unordered_map<char, char> hmap_from_s_to_t;
    unordered_map<char, char> hmap_from_t_to_s;

    if(input1.length() != input2.length())
        return false; 
        
    for(int i = 0; i < s.length(); i++){
        if(hmap_from_s_to_t.find(s[i]) != hmap_from_s_to_t.end()) {
            // Element is found 
            if(hmap_from_s_to_t[s[i]] != t[i])
                return false;
        } else {
            hmap_from_s_to_t[s[i]] = t[i];
        }
        // Reverse mapping 
        if(hmap_from_t_to_s.find(t[i]) != hmap_from_t_to_s.end()) {
            // Reverse Element is found 
            if(hmap_from_t_to_s[t[i]] != s[i])
                return false;
        } else {
            hmap_from_t_to_s[t[i]] = s[i];
        }
    }
    return true;
    }
};