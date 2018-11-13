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

    /////////////////////////////////////////////////////////
    // Alternate solution 
    /////////////////////////////////////////////////////////

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseStr(string &s, int i, int j){
        while(i < j){
          char t = s[i];
          s[i++] = s[j];
          s[j--] = t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i = 0, j = 0;
        int l = 0;
        int len = s.length();
        int wordcount = 0;
        
        while(true){
            while(i < len && s[i] == ' ') 
                i++;  // skip spaces in front of the word
            if(i == len) 
                break;
            if(wordcount) 
                s[j++] = ' ';
            l = j;
            while(i < len && s[i] != ' ') 
            {
                s[j] = s[i]; 
                j++; i++;
            } 
            reverseStr(s, l, j - 1);                // reverse word in place
            wordcount++;            
        }        
        s.resize(j); // resize result string
        reverseStr(s, 0, j - 1); // reverse whole string
    }
};