#include "./../../Include/Common.h"

/*
    . Design HashMap
*/

class MyHashMap {
    private: 
    vector<int> data;

    public:
    MyHashMap() {
        data = vector<int>(1000000, -1);
    }

    int hashFn(int key){
        return key;
    }
    
    void put(int key, int value) {
        data[key] = value;
    }
    
    int get(int key) {
        return data[key];
    }
    
    void remove(int key) {
        data[key] = -1;
    }
};