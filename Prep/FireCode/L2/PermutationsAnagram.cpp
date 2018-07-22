#include "./../../../Include/Common.h"
using namespace std;


bool permutation(string input1, string input2)
{
    char database1[100] = {0,};
    char database2[100] = {0,};
    
    int n1 = input1.length();
    int n2 = input2.length();
    
    if(n1 != n2)
        return false;
    
    for(int i = 0; i < input1.length(); i++){
        database1[input1[i] - 'a']++;
    }
    for(int i = 0; i < input2.length(); i++){
        database2[input2[i] - 'a']++;
    }
    
    for(int i = 0; i < 100; i++){
        
        if(database1[i] != database2[i])
            return false;
    }
    return true;
}