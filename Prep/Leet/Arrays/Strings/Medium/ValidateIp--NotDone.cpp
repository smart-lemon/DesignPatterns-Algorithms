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
    
    }
    
    bool validateIpv4(string arr){
        
               
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