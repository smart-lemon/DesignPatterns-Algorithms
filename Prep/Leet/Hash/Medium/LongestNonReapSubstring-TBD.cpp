#include "./../../Include/Common.h"

/*
    3. Longest Substring Without Repeating Characters

    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unrordered_map<char, int> hashmap; 
        int left = 0, max = 0; 
        for(int right = 0; right < s.length(); right++){
            if(hashmap.find(s[right]) != hashmap.end()) {
                hashmap[s[right]] = right; 
            } else {
                if(right - left > max)
                    max = right - left;
                // Remove key from map
                hashmap.erase(s[left]); 
                left++;
            }
        }
        return max;
    }
};