#include "./../../Include/Common.h"


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> hashmap; 
        
        for(int i = 0; i < J.length(); i++){
            hashmap[J[i]]++;
        }
        
        for(int i = 0; i < S.length(); i++){
            if(hashmap.find(S[i]) != hashmap.end()){
                hashmap[S[i]]++;
            }
        }
        
        int sum = 0;
        for(auto jewels : hashmap){
            sum += (jewels.second - 1); 
        }
        return sum;
    }
};