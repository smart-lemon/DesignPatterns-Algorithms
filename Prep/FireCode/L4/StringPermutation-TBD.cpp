 #include "./../../../Include/Common.h"

vector<string> permutationOutput;

static int n = 0;
void do_permutations(string str, int i, int n)
{
    // Base condition
    if (i == n - 1)
    {
        permutationOutput.push_back(str);
        return;
    }

    // Process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // Swap character at index i with current character
        swap(str[i], str[j]);        // STL swap() used

        // Recurse for string [i+1, n-1]
        do_permutations(str, i + 1, n);

        // Backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}

vector<string> get_permutations(string s) 
{    
    n = s.length();  
    do_permutations(s, 0, s.length());
    return permutationOutput;
}