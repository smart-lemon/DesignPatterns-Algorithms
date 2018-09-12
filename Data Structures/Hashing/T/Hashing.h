#include <cmath>
using namespace std;

// Template for generic types
template<typename Key, typename Val>
class HashNodeT
{
    public:
    Key key;
    Val value;

    // This constructor is only for the root node of each bucket
    HashNodeT()
    {
        // Dont store any key-value
    }

    // Actual constructor of HashNodeT 
    HashNodeT(Key k, Val v)
    {
        value = v;
        key = k;
    }   
    
    // 
    HashNodeT<Key, Val> *next;
};


template<typename Key, typename Val>
class HashMapT {

    int capacity;
    
    // # of buckets
    int noOfBuckets; 
    int loadFactor = 2;
    int population;

    private:

    void deleteTable(HashNodeT<Key, Val> **toBeDeleted){
        
        // Destroy all buckets one by one
        for (int i = 0; i < noOfBuckets; i++) {
            if(toBeDeleted[i]->next != NULL){
                HashNodeT<Key, Val> *entry = toBeDeleted[i]->next;
                while (entry != NULL) {
                    HashNodeT<Key, Val> *prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
        }
        // Destroy the hash table
        delete [] toBeDeleted;
    }

    HashNodeT<Key, Val> **createTable (int iNoOfBuckets){
         // A table containing pointers to HashNodeTs
        HashNodeT<Key, Val> **freshTable = new HashNodeT<Key, Val> *[iNoOfBuckets];

        // Initialise all buckets as NULL (Nothing in the root HashNodeT)
        for(int i = 0 ; i < iNoOfBuckets ; i++){
            freshTable[i] = new HashNodeT<Key, Val>;
            freshTable[i]->next = NULL;
        }
        return freshTable;
    }

    HashNodeT<Key, Val> **table;

    public:
  
    int hashCode(Key key)
    {
        // cout << "Hash Func "<< key << " " << noOfBuckets << endl;      
        // Re interpret 'key' as int
        return reinterpret_cast<int>(key) % noOfBuckets;
    }
    
    HashMapT(int size) {

        capacity = size;
        noOfBuckets = size/loadFactor;
        population = 0;

        table = createTable(noOfBuckets);
    }

    void insert(Key ikey, Val ival){

        HashNodeT<Key, Val> *temp = new HashNodeT<Key, Val>(ikey, ival);
         
        // Apply hash function to find index for given key
        int hashIndex = hashCode(ikey);

        // Add the key value data
        temp->key = ikey;
        temp->value = ival;

        // Add the previous node as the next of the new node
        temp->next = table[hashIndex]->next;

        // Attach the new node to the root of the bucket 
        table[hashIndex]->next = temp;

        population++; // Current population 

        if(population > capacity)
            capacity = population;

        if(ceil(float(population) / noOfBuckets) > loadFactor)
            rehash();
    }

    Val search(Key ikey){

        // Identify the bucket
        int index = hashCode(ikey);

        HashNodeT<Key, Val> *next = table[index]->next;

        // Seach the bucket items for the key 
        // and return the value if found
        while(next){
            if(next->key == ikey)
                return next->value;
            next = next->next;
        }
    }

    void remove(Key ikey) {
        int hashValue = hashCode(ikey);

        HashNodeT<Key, Val> *prev = NULL;
        HashNodeT<Key, Val> *entry = table[hashValue]->next;

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

        HashNodeT<Key, Val> **oldTable;
        oldTable = table;
        
        int oldNoOfBuckets = noOfBuckets;

        // Double the bucket size
        noOfBuckets = noOfBuckets * 2;

        cout << endl << "Rehashing to " << noOfBuckets << " Buckets" << endl;

        // Create a new HashTable 
        table = createTable(noOfBuckets);

        for(int i = 0; i < oldNoOfBuckets ; i++)
        {
            if(oldTable[i]->next != NULL)
            {   
                // For every item in the old hash table, recomput the new 
                for(auto temp = oldTable[i]->next; temp; temp = temp->next)
                {
                    int newIndex = hashCode(temp->key);

                    HashNodeT<Key, Val> *newTemp = new HashNodeT<Key, Val>(temp->key, temp->value);
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
                cout << "[" << i << "]: "; // Print the bucket number
                for(auto temp = table[i]->next; temp; temp = temp->next)
                {
                    // And the key-values
                    if(temp)
                        cout << "(K: " << temp->key << " V: " << temp->value << ") -> " ;
                }
                cout <<  "NULL" << endl;
            }
        }
    }

    ~HashMapT() {
        deleteTable(table);
    }

};  
