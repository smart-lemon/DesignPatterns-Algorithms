#include "./../../Include/Common.h"

/*
    . Design HashMap
*/

class MyHashMap {

    public:
    vector<int> data;

    MyHashMap() {
    }
    
    void add(int key) {
        data.pushback;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == true;
    }
};