// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
bool is_string_palindrome(string str)
{
    // Add your code below this line. Do not modify any other code.
    if(str.length() <= 1)
        return true;
    
    int low = 0; 
    int high = str.length() - 1; 
    
    while(low != high){
        if(str[low] != str[high])
            return false; 
        else {
            low++; 
            high--;
        }
    }
    return true; 
    // Add your code above this line. Do not modify any other code.
}