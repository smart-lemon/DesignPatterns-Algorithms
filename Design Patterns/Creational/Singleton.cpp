#include "./../../Include/Common.h"

class Singleton {
    
    private: 
    Singleton(){
        // ... Private Constructor
    }

    static Singleton *uniqueInstance;

    public:
    
    static Singleton *getInstance(){
        if(uniqueInstance == nullptr){
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
    }
};


Singleton* Singleton::uniqueInstance = 0;

void testSingleton()
{
    Singleton *instance = Singleton :: getInstance();
}