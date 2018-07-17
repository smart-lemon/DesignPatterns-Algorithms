// namespace std have been included for this problem.
#include <unordered_map> 

// Add any helper functions(if needed) above.
char first_non_repeating(string str)
{
    char non_repeating = '\0';
    unordered_map<char, int> hmap; 
    
    for(int i = 0 ; i < str.length(); i++){
        hmap[str[i]]++;
    }
    for(int i = 0 ; i < str.length(); i++){
        if(hmap[str[i]] == 1) {
            return str[i];
        }
    }
    
    return '0';
}