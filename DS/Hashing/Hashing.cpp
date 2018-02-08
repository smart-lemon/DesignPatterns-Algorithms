#include "./../../Include/CommonInc.h"
#include <cmath>

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
    int noOfBuckets; // # of buckets
    int loadFactor = 2;
    int population;

    private:

    void deleteTable(HashNode<Key, Val> **toBeDeleted){
        // Destroy all buckets one by one
        for (int i = 0; i < noOfBuckets; i++) {
            if(toBeDeleted[i]->next != NULL){
                HashNode<Key, Val> *entry = toBeDeleted[i]->next;
                while (entry != NULL) {
                    HashNode<Key, Val> *prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
        }
        // Destroy the hash table
        delete [] toBeDeleted;
    }

    HashNode<Key, Val> **createTable (int iNoOfBuckets){
         // A table containing pointers to HashNodes
        HashNode<Key, Val> **freshTable = new HashNode<Key, Val> *[iNoOfBuckets];

        // Initialise all buckets as NULL (Nothing in the root HashNode)
        for(int i = 0 ; i < iNoOfBuckets ; i++){
            freshTable[i] = new HashNode<Key, Val>;
            freshTable[i]->next = NULL;
        }
        return freshTable;
    }

    HashNode<Key, Val> **table;

    public:
  
    int hashCode(Key key)
    {
        // cout << "Hash Func "<< key << " " << noOfBuckets << endl;      
        // Re interpret 'key' as int
        return reinterpret_cast<int>(key) % noOfBuckets;
    }
    
    HashMap(int size) {

        capacity = size;
        noOfBuckets = size/loadFactor;
        population = 0;

        table = createTable(noOfBuckets);
    }

    void insert(Key ikey, Val ival){

        HashNode<Key, Val> *temp = new HashNode<Key, Val>(ikey, ival);
         
        // Apply hash function to find index for given key
        int hashIndex = hashCode(ikey);

        // Add thekey value data
        temp->key = ikey;
        temp->value = ival;

        // Add the previous node as the next of the new node
        temp->next = table[hashIndex]->next;

        // Attach the new node to the root of the bucket 
        table[hashIndex]->next = temp;

        population++; // Current population 

        if(ceil(float(population) / noOfBuckets) > loadFactor)
            rehash();
    }

    Val search(Key ikey){

        int index = hashCode(ikey);

        HashNode<Key, Val> *next = table[index]->next;

        while(next){
            if(next->key == ikey)
                return next->value;
            next = next->next;
        }
        return NULL;
    }

    void remove(Key ikey) {
        int hashValue = hashCode(ikey);
        HashNode<Key, Val> *prev = NULL;
        HashNode<Key, Val> *entry = table[hashValue]->next;

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
                table[hashValue]->next = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;

            population--; // Reduce population
        }
    }

    void rehash(){

        HashNode<Key, Val> **oldTable;
        oldTable = table;
        
        int oldNoOfBuckets = noOfBuckets;
        noOfBuckets = noOfBuckets * 2;

        cout << "Rehashing : " << noOfBuckets << " Buckets" << endl;

        table = createTable(noOfBuckets);

        for(int i = 0; i < oldNoOfBuckets ; i++)
        {
            if(oldTable[i]->next != NULL)
            {   
                for(auto temp = oldTable[i]->next; temp; temp = temp->next)
                {
                    int newIndex = hashCode(temp->key);

                    HashNode<Key, Val> *newTemp = new HashNode<Key, Val>(temp->key, temp->value);
                    newTemp->next = table[newIndex]->next;
                    table[newIndex]->next = newTemp;
                }
            }
        }

        // deleteTable(oldTable);
    }

    void printHashMap(){

        // For every bucket of the table
        for(int i = 0; i < noOfBuckets; i++)
        {
            if(table[i]->next != NULL)
            {   
                cout << "[" << i << "]: ";
                for(auto temp = table[i]->next; temp; temp = temp->next)
                {
                    if(temp)
                        cout << "(K: " << temp->key << " V: " << temp->value << ") -> " ;
                }
                cout <<  "NULL" << endl;
            }
        }
    }

    ~HashMap() {
        deleteTable(table);
    }
};  


void testHashing(){

    HashMap<int, int> *hashMap = new HashMap<int, int>(30);

    for(int k = 0; k < 35; k++)
        hashMap->insert(k + 1, (k + 1) * 100);

    hashMap->printHashMap();  
  
    int val = hashMap->search(29);

    cout << val;

}