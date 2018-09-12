#include "./../../Include/Common.h"


// Template for generic types
class HashNode
{
    public:
  
    int value;

    // This constructor is only for the root node of each bucket
    HashNode()
    {
        // Dont store any key-value
    }

    // Actual constructor of hashnode 
    HashNode(int v)
    {
        value = v;
    }   

    HashNode *next;
};



class HashSet {
   
    public:
    int capacity;
    
    // # of buckets
    int noOfBuckets; 
    int loadFactor = 2;
    int population;

    HashNode **table;

    HashSet(int size) {
        capacity = size;
        noOfBuckets = size/loadFactor;
        population = 0;

        table = createTable(noOfBuckets);
    }


    HashNode **createTable (int iNoOfBuckets){
         // A table containing pointers to HashNodes
        HashNode **freshTable = new HashNode *[iNoOfBuckets];

        // Initialise all buckets as NULL (Nothing in the root HashNode)
        for(int i = 0 ; i < iNoOfBuckets ; i++){
            freshTable[i] = new HashNode;
            freshTable[i]->next = nullptr;
        }
        return freshTable;
    }

    int hashCode(int value)
    {
        // cout << "Hash Func "<< key << " " << noOfBuckets << endl;      
        return value % noOfBuckets;
    }


    void add(int ival){

         
        // Apply hash function to find index for given key
        int hashIndex = hashCode(ival);

        // Add the previous node as the next of the new node
        if(table[hashIndex]->next) {
            HashNode *runner = table[hashIndex]->next;
            while(runner){
                if(runner->value == ival){
                    // Do nothing, dont add dupes to a set
                    break;
                }
            }
            if(runner == nullptr){
                HashNode *temp = new HashNode(ival);

                // Add the value data
                temp->value = ival;

                temp->next = table[hashIndex]->next;
                table[hashIndex]->next = temp;
                population++; // Current population 

            }
        }

        // Increase the capacity if needed
        if(population > capacity)
            capacity = population;

        if(ceil(float(population) / noOfBuckets) > loadFactor)
            rehash();
    }

    /*
        If the key exists then return it as the send parameter
    */
    bool contains(int & value){

        // Identify the bucket
        int index = hashCode(ival);

        HashNode *next = table[index]->next;

        // Seach the bucket items for the key 
        // and return the value if found
        while(next){
            if(next->value == ival){
                value = next->value;
                return true;
            }
            next = next->next;
        }

        return false;
    }

    bool remove(int ival) {
        int hashValue = hashCode(ival);

        HashNode *prev = NULL;
        HashNode *entry = table[hashValue]->next;

        // Try to find the key
        while (entry != NULL && entry->value != ival) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == NULL) {
            // Key not found
            return false;
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

        HashNode **oldTable;
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

                    HashNode *newTemp = new HashNode(temp->key, temp->value);
                    newTemp->next = table[newIndex]->next;
                    table[newIndex]->next = newTemp;
                }
            }
        }

        // deleteTable(oldTable);
    }
};