
#include "./../../../../Include/Common.h"
/*
    Find the longest palindromic substring in s 


*/


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int longestSubstring = 1;
        string ans;

        for(int center = 0; center < len; center++) {            
            int offset = 1;
            int currentSubLen = 1;
            while( center - offset >= 0 && center + offset < len && 
                   s[center - offset] == s[center + offset] ){
                currentSubLen += 2;
                offset++;
                if(currentSubLen > longestSubstring) {
                    longestSubstring = currentSubLen; 
                    ans = s.substr(center - offset, currentSubLen);
                }
            }
        }
        return ans;
    }
};