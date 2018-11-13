#include "./../../../../Include/Common.h"

/*
      Reverse Words in a String III:
      Reverse the characters in a word within a sentence while still preserving whitespace 
      and initial word 

*/
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int left = 0, right = 0, start = 0, sz = s.size();
        
        while(true){
            while(left < sz && s[left] == ' ')
                left++, right++;

            while(right < sz && s[right] != ' ')
                right++;
                
            reverse(s.begin() + left, s.begin() + right);
            
            right++;
            left = right;

            if(right >= sz - 1)
                break;
        }
        return s;
    }
};



/*
    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"
*/