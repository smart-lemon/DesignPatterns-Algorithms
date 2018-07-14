#include "./../../../Include/Common.h"

// Add any helper functions(if needed) above.
bool are_all_characters_unique(string str)
{
    // Add your code below this line. Do not modify any other code.      
    if(str.length() == 0)
        return true;
        
    unordered_map<char, int> char_occurences; 
    
    for(int i = 'a'; i <= 'z'; i++){
        char_occurences[i] = 0; 
    }
    
    for(int i = 0; i < str.length(); i++){
        if(char_occurences[str[i]] == 1)
            return false; 
        else 
            char_occurences[str[i]]++; 
    }
    
    return true; 
    // Add your code above this line. Do not modify any other code.
}