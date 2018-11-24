#include "./../../../../Include/Common.h"

/*
    Determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

*/
inline bool isEqual(char a, char b) {
    cout <<  a << " "  << (char)(b -'A') << (char)(a - 'A') << endl;
    if(a == b || a == (char)('A' - b) || b == (char)('A' - a))
        return true;
    return false;
}


bool isNotAlphanumeric(char thing) {
    if((thing == ' ') || (thing == '\'') || (thing == ',') ||
       (thing == ':') || (thing == '.')  || (thing == '?')){
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
        
        while(low != high){
            // cout << str[low] << " " << str[high] << "."; 
            if(isEqual(str[low], str[high])){
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