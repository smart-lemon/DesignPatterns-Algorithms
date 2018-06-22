#include "./../../../Include/Common.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>


class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
        
        unordered_set<char> qweSet;
        qweSet.insert('q'); qweSet.insert('w'); qweSet.insert('e');
        qweSet.insert('r'); qweSet.insert('t'); qweSet.insert('y'); 
        qweSet.insert('u'); qweSet.insert('i'); qweSet.insert('o');
        qweSet.insert('p');
        
        unordered_set<char> asdSet;
        asdSet.insert('a'); asdSet.insert('g'); asdSet.insert('k');
        asdSet.insert('s'); asdSet.insert('h'); asdSet.insert('l'); 
        asdSet.insert('d'); asdSet.insert('j'); 
        asdSet.insert('f');
        
        unordered_set<char> zxcSet;
        zxcSet.insert('z'); zxcSet.insert('b'); zxcSet.insert('k');
        zxcSet.insert('x'); zxcSet.insert('n');
        zxcSet.insert('c'); zxcSet.insert('m'); 
        zxcSet.insert('v');
        
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