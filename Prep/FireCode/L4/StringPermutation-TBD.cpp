#include "./../../../Include/Common.h"

vector<string> permutationOutput;

static int n = 0;

void permuteString(string str, int i) {
    if(i == n - 1){
        permutationOutput.push_back(str);
        return;
    }

    for(int j = i; j < n; j++){
        swap(str[i], str[j]);
        permuteString(str, i + 1);
        swap(str[i], str[j]);
    }
}

vector<string> get_permutations(string s) 
{    
    n = s.length();  
    permuteString(s, 0);
    return permutationOutput;
}