#include "./../../Include/CommonInc.h"

using namespace std;

// Template for generic types
template<typename Key, typename Val>
class HashNode
{
    public:
    Key key;
    Val value;

  //Constructor of hashnode 
    HashNode(Key k, Val v)
    {
        value = v;
        key = k;
    }   
    
    // HashNode<Key, Val> *next;
};


template<typename Key, typename Val>
class HashMap {

    int capacity;
    int tableSize; // # of buckets
    int loadFactor = 20;
    int population;

    public:
    HashNode<Key, Val> *table;

    int hashCode(Key key)
    {
        return key % capacity;
    }
    
    HashMap(int size) {

        capacity = size;
        tableSize = size/loadFactor;
        population = 0;

        // A table containing pointers to HashNodes
        table = new HashNode<Key, Val> [tableSize];

        // Initialise all buckets as NULL (Nothing in the root HashNode)
        for(int i = 0 ; i < tableSize ; i++){
            table[i]->next = NULL;
        }
    }

    void insert(Key key, Val value){

        HashNode<Key, Val> *temp = new HashNode<Key, Val>(key, value);
         
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        // Add the previous node as the next of the new node
        temp->next = table[hashIndex]->next;
        // Attach the new node to the root of the bucket 
        table[hashIndex]->next = table->next;

        population++;

        if(population / tableSize > loadFactor)
            rehash();
    }

    void rehash(){

    }


};  


void testHashing(){

}