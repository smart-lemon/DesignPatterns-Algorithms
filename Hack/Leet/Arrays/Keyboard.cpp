#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_set>

// https://leetcode.com/problems/keyboard-row

class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
        
        unordered_set<char> qweSet;        
        unordered_set<char> asdSet;        
        unordered_set<char> zxcSet;
        
        string rowOne   = "qwertyuiop";
        string rowTwo   = "asdfghjkl";
        string rowThree = "zxcvbnm";

        int strLen = rowOne.size(); 
        for(int i = 0; i < strLen; i++){
            qweSet.push_back(rowOne[i]);
        }

        strLen = rowTwo.size();
        for(int i = 0; i < strLen; i++){
            asdSet.push_back(rowTwo[i]);
        }

        strLen = rowThree.size();
        for(int i = 0; i < strLen; i++){
            zxcSet.push_back(rowOne[i]);
        }

        vector<string> output;
        vector<unordered_set<char>> keyboard; 
        keyboard.push_back(qweSet);
        keyboard.push_back(asdSet);
        keyboard.push_back(zxcSet);
        

        int number_of_words = words.size();
        vector<string> choice;
        for(int i = 0; i < number_of_words; i++){
            choice.push_back(words[i]);
        }

        for(int list = 0; list < number_of_words; list++){
            int word_len = words[list].size();
            int row_found = -1;
            transform(words[list].begin(), words[list].end(), words[list].begin(), ::tolower);

            for(int row = 0; row < keyboard.size(); row++){
                char search = words[list][0];
                if(keyboard[row].find(search) != keyboard[row].end()){
                    row_found = row;
                    break;
                }
            }
            bool found = true;
            int characters = 0;
            for(characters = 1; characters < word_len; characters++){
                char search = words[list][characters];
                if(keyboard[row_found].find(search) == keyboard[row_found].end()){
                    found = false;
                }
            }
            if(found) {
                output.push_back(choice[list]);
            }
        }
        return output;
    }
};