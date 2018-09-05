
/*
    https://leetcode.com/problems/longest-valid-parentheses/description/
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(); 
        int left = 0, right = 0, max_length = 0, index = 0; 
        while(index < len){
            if(s[index] == '(')
                left++;
            else 
                right++;
            
            if(right == left){
                max_length = max(max_length, 2 * right); 
            } else if(right > left) {
                right = left = 0; 
            }        
            index++;
        }
        
        index = len - 1;
        right = left = 0; 
        while(index >= 0){
            if(s[index] == ')')
                left++;
            else 
                right++;
            
            if(right == left){
                max_length = max(max_length, 2 * right); 
            } else if(right > left) {
                right = left = 0; 
            }        
            index--;
        }
        return max_length; 
    }
};