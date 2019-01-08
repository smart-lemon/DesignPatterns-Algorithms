
#include "./../../../../Include/Common.h"
/*
    Find the longest palindromic substring in s 


*/


class Solution {
public:

    bool isPalindromeSeed(string s, int idx, int & left, int & right){
        // abba case
        if(s[idx] == s[idx - 1]){
            left = idx - 1; 
            right = idx;
            return true;
        }

        // owo case
        if(s[idx - 1] == s[idx + 1]){
            left = idx - 1; 
            right = idx + 1;
            return true;
        }
        return false;
    }

    string longestPalindrome(string s) {
        int len = s.length();

        if(len <= 1)
            return s;

        int longestSubstring = 1;
        string ans;

        for(int center = 1; center < len - 1; center++) {            
            int offset = 1;
            int currentSubLen = 1;
            int left = 0, right = 0;
            if(isPalindromeSeed(s, center, left, right)){
                while(left >= 0 && right < len && 
                    s[left] == s[right] ){
                    currentSubLen = right - left;
                    if(currentSubLen > longestSubstring) {
                        longestSubstring = currentSubLen; 
                        ans = s.substr(left, currentSubLen + 1);                    
                    }
                    left--; right++;
                }
            }            
        }
        return ans;
    }
};