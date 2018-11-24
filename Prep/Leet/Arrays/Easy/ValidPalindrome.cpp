#include "./../../../../Include/Common.h"

/*
    Determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

*/

int toUpperChar(int ch){
    if(ch >= 'a' && ch <= 'z')
        return ('A' + ch - 'a');
    else
        return ch;
}

bool isNotAlphanumeric(char thing) {
    if((thing == ' ') || (thing == '\'') || (thing == ',') ||
       (thing == ':') || (thing == '.')  || (thing == '?') ||
       (thing == '@') || (thing == '#')  || (thing == '-') ||
       (thing == '\"')|| (thing == ';')  || (thing == ')') ||
       (thing == '!') || (thing == '(')  || (thing == '`')){
        return true;
    }
    return false;
}

class Solution {
public:
    bool isPalindrome(string str) {
        if(str.length() <= 1)
            return true;
    
        int low = 0; 
        int high = str.length() - 1; 
        
        while(low < high){
            // cout << str[low] << " " << str[high] << "."; 
            if(toUpperChar(str[low]) == toUpperChar(str[high])){
                low++; 
                high--;            
            } else {
                if(isNotAlphanumeric(str[low])){
                    low++;
                    continue;
                }
                if(isNotAlphanumeric(str[high])){
                    high--;
                    continue;
                }
                return false;
            }
        }
        return true;  
    }
};

    bool isPalindrome(string s) {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[left]) == false &&  left < right) 
                left++; // Increment left pointer if not alphanumeric
            while (isalnum(s[right]) == false &&  left < right) 
                right--; // Decrement right pointer if no alphanumeric
            if (toupper(s[left]) != toupper(s[right])) 
                return false;
        }
    }    
};