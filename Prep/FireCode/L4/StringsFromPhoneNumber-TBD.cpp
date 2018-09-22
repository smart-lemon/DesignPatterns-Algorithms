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


vector<string> get_strings_from_nums(string digits) 
{
    
}