#include "./../../../Include/Common.h"

/*
    Given a string that represents the digits pressed on a classic cell phone keypad - 
    return all possible letter combinations that the numbers
    
    Mapping:
        2 -> "abc"
        3 -> "def"
        4 -> "ghi"
        5 -> "jkl"
        6 -> "mno"
        7 -> "pqrs"
        8 -> "tuv"
        9 -> "wxyz"

        Example:
        Input  : "34" 
        Output : [dg, dh, di, eg, eh, ei, fg, fh, fi]

*/


string lookup[] = { "",    "", 
                    "abc", "def",
                    "ghi", "jkl",
                    "mno", "pqrs",
                    "tuv", "wxyz" };

vector <string> output; 

void recursive_phone_combination(string & digits, int current_idx, string & formation) {
   
    if(current_idx == digits.length()){
        output.push_back(formation);
        //cout << formation << endl;
        return;
    }
   // cout << formation << " " << current_idx << endl;
    int lookup_address = digits[current_idx] - '0';

    for(int i = 0; i < lookup[lookup_address].length(); i++){
        
        if(lookup_address == 0 || lookup_address == 1 )
            continue;
        recursive_phone_combination( digits, current_idx + 1, 
                                     formation += lookup[lookup_address][i] );
        formation.pop_back(); // C++11 exclusive
    }
}

vector<string> get_strings_from_nums(string digits) {
    string temp;
    output.clear();
    recursive_phone_combination(digits, 0, temp);
    return output;
}