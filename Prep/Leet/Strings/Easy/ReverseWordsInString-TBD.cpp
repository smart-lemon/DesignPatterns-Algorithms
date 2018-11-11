#include "./../../../../Include/Common.h"

/*
    151. Reverse Words in a String:
    Reverse the string word by word.

    https://leetcode.com/problems/reverse-words-in-a-string/
*/
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length(); 
        int right = n - 1, left = n - 2;

        // Handle corner cases 

        if(left < 0)
            return;

        string res = "";
        while(left >= 0){
            
            while(left > 0 && s[left] != ' ')
                left--;
            
            if(left >= 0) {
                res += s.substr(left + 1, right - left); 
                res += " ";
            }

            left -= 2;
            right = left + 1;
        }
        
        s = res;
    }
};