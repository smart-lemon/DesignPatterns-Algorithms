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
                if(right - left > max)
                    max = right - left;
            } else {
                // Remove key from map
                left++;
            }
            hashmap[s[right]] = right;
        }
        return max;
    }
};

int result(0),current(0);
            unordered_map<char,int> hash;
            for(int i=0;i<s.size();i++){
                if(hash.find(s[i]) != hash.end()){
                    result = max(result,current);
                    current = min(i-hash[s[i]],current+1);
                }
                else{
                    current++;
                }
                hash[s[i]] = i;
            }
            return max(result,current);