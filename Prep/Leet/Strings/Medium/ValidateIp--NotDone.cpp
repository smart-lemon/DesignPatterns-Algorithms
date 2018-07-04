#include "./../../../../Include/Common.h"
using namespace std;

class Solution {
public:
    
    bool isIpv4(string IP) {
        if(string::npos == IP.find("."))
            return false; 
        return true;
    }
    
    bool isIpv6(string IP) {
        if(string::npos == IP.find(":"))
            return false; 
        return true;
    }
    
    bool validateIpv4Block(string block) {
        int len = block.length();
        // 1. If first char is zero rest are not char. 
        int num = 0, numberCnt = 0;
        for(int i = 0; i < len; i++){
            int it = block[i] - '0'; 
            num = (num * 10) + it;
            numberCnt++;
            if(numberCnt > 3){
                    cout << "More than 3 numbers " << endl;
                    return false;
            }
        // if the 
        }
        if(num > 255 || num < 0)
        {
            cout << "The number is more than 255 -> " << num << endl;
            return false; 
        }
    }
    
    bool validateIpv4(string arr){
        
        string r = arr.substr(1, 3);
        int start = 0, dots = 0; 
        int next = arr.find(".");
        while(next != string::npos){
            string block = arr.substr(start, next);
            validateIpv4Block(block);
            start = next + 1;
            next = arr.find(".");
        }

        if(!dots == 3)
            return false;
               
        return true; 
    }
    
    bool validateIpv6Block(string arr){
        int len = arr.length(); 
        
        for(int i = 0; i < len; i++){
            
        }
        return true; 
    }
    
    bool validateIpv6(string arr){
        int len = arr.length(); 
        
        for(int i = 0; i < len; i++){
            
        }
        return true; 
    }
    
    
    string validIPAddress(string IP) {
        if(isIpv4(IP))
            if(validateIpv4(IP))
                return "IPv4";
         if(isIpv6(IP))
            if(validateIpv6(IP))
                return "IPv6";
        return "Neither";
    }
};