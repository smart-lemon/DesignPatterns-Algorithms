#include "./../../Include/Common.h"

using namespace std;



class Singleton {
    
    private: 
    Singleton(){
        // ... Private Constructor
    }

    static Singleton *uniqueInstance;

    public:
    
    static Singleton *getInstance(){
        if(uniqueInstance == 0){
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
    }
};


void testSingleton()
{
    Singleton *instance = Singleton::getInstance();
}