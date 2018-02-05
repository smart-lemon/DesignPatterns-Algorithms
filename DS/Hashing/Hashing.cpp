#include "./../../Include/CommonInc.h"

using namespace std;

// Template for generic types
template<typename Key, typename Val>
class HashNode
{
    public:
    Key key;
    Val value;

    HashNode()
    {
    }

  //Constructor of hashnode 
    HashNode(Key k, Val v)
    {
        value = v;
        key = k;
    }   
    
    HashNode<Key, Val> *next;
};


template<typename Key, typename Val>
class HashMap {

    int capacity;
    int tableSize; // # of buckets
    int loadFactor = 20;
    int population;

    private:

    void deleteTable(HashNode<Key, Val> *toBeDeleted){
        // Destroy all buckets one by one
        for (int i = 0; i < tableSize; i++) {
            HashNode<Key, Val> *entry = toBeDeleted[i].next;
            while (entry != NULL) {
                HashNode<Key, Val> *prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        // Destroy the hash table
        delete [] toBeDeleted;
    }

    HashNode<Key, Val> *createTable (int iTableSize){
         // A table containing pointers to HashNodes
        HashNode<Key, Val> *freshTable = new HashNode<Key, Val>[iTableSize];

        // Initialise all buckets as NULL (Nothing in the root HashNode)
        for(int i = 0 ; i < iTableSize ; i++){
            freshTable[i].next = NULL;
        }
        return freshTable;
    }

    HashNode<Key, Val> *table;

    public:
  
    int hashCode(Key key)
    {
        // Re interpret 'key' as int
        // return reinterpret_cast<int>(key) % tableSize;
        return key % tableSize;
    }
    
    HashMap(int size) {

        capacity = size;
        tableSize = size/loadFactor;
        population = 0;

        table = createTable(tableSize);
    }

    void insert(Key ikey, Val ival){

        HashNode<Key, Val> *temp = new HashNode<Key, Val>(ikey, ival);
         
        // Apply hash function to find index for given key
        int hashIndex = hashCode(ikey);

        // Add thekey value data
        temp->key = ikey;
        temp->value = ival;

        // Add the previous node as the next of the new node
        temp->next = table[hashIndex].next;

        // Attach the new node to the root of the bucket 
        table[hashIndex].next = temp;

        population++; // Current population 

        if(population / tableSize > loadFactor)
            rehash();
    }

    Val search(Key ikey){

        int index = hashCode(ikey);

        HashNode<Key, Val>  *next = table[index].next;

        while(next){
            if(next->key == ikey)
                return next->value;
            next = next->next;
        }
    }

    void remove(Key ikey) {
        int hashValue = hashFunc(ikey);
        HashNode<Key, Val> *prev = NULL;
        HashNode<Key, Val> *entry = table[hashValue].next;

        // Try to find the key
        while (entry != NULL && entry->key != ikey) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == NULL) {
            // Key not found
            return;
        } else { 
            // Key is found
            if (prev == NULL) {
                // Remove first bucket of the list
                table[hashValue].next = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;

            population--; // Reduce population
        }
    }

    void rehash(){
        HashNode<Key, Val> *oldTable;

        oldTable = table;
        int oldTableSize = tableSize;
        tableSize = tableSize * 2;

        table = createTable(tableSize);

        // For every bucket of the old table
        for(int i = 0; i < oldTableSize ; i++)
        {
            if(oldTable[i].next != NULL)
            {   
                for(auto temp = oldTable[i].next; temp; temp = temp->next)
                {
                    int newIndex = hashCode(temp->key);
                    auto newTemp = temp;
                    temp = temp->next;
                    newTemp->next = table[newIndex].next;
                    table[newIndex].next = newTemp;
                }
            }
        }

        deleteTable(oldTable);
    }

    ~HashMap() {
        deleteTable(table);
    }
};  


void testHashing(){

    HashMap<int, int> *hashMap = new HashMap<int, int>(30);

    hashMap->insert(1, 100);
    hashMap->insert(2, 200);
    hashMap->insert(3, 300);

    int val = hashMap->search(3);

    cout << val;

}