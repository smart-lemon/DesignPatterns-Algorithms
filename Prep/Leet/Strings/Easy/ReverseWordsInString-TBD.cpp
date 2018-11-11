#include "./../../../../Include/Common.h"

/*
    151. Reverse Words in a String:
    Reverse the string word by word.

    https://leetcode.com/problems/reverse-words-in-a-string/
*/
class Solution {
public:
    void reverseWords(string &s) {
        string result;
        int left = 0;
        for (int right = 0; right < s.size(); right++){
            if (s[right] == ' ') {
                if (right > left )
                    result = s.substr(left, right - left) + " " + result ;
                left = right + 1;
            } else if (right == s.size() - 1) {
                result = s.substr(left, s.size() - left) + " " + result;
            }
        }
        // To avoid the " " at the end
        s = result.substr(0, result.size() - 1) ;
    }
};