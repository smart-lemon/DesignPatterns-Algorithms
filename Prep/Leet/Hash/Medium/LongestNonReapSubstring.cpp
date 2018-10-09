#include "./../../Include/Common.h"

/*
    3. Longest Substring Without Repeating Characters

    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest(0), current(0);
        unordered_map<char,int> hash;
        for(int right = 0; right < s.size(); right++){
            if(hash.find(s[right]) != hash.end()){
                longest = max(longest, current);
                current = min(right - hash[s[right]], current + 1);
            } else {
                current++;
            }
            hash[s[right]] = right;
        }
        return max(longest, current);
    }
};


/*
    This is a bit tricky. 

    →  current will calculate the length of the substring so far
        → It can be the minimum of right - hash[s[right]] OR the last calculated current + 1
        → In the "abba" test case for ab, current goes to 2
            Next for b, current is reduced to 1. 
            Then for a, current can be minimum of 
            →  right - hash['a'] which is 3 or current + 1 = 2 for the 'ba' substring
*/