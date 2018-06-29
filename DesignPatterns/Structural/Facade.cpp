#include "./../../Include/Common.h"
#include <string>
#include <unordered_map>
#include <utility> 
#include <functional>

using namespace std;

// Step 1 : Design the Interface
class IAccount {
    protected: 
    int accountNo;
    int cash;

    public:
    virtual void deposit(float amount);
    virtual void withdraw(float amount);
    virtual void transfer(float amount);
    virtual int getAccountNumber() = 0;
};

// Step 2 : Implement the interface with one or more subtypes
class Current : public IAccount{
    public:
    Current(int amt) { cash = amt; }

    int getAccountNumber() {
        return accountNo;
    }
};

class Savings : public IAccount{
    public:
    Savings(int amt) { cash = amt; }

    int getAccountNumber() {
        return accountNo;
    }
};

class Investments : public IAccount{
    public:
    Investments(int amt) { cash = amt; }

    int getAccountNumber() {
        return accountNo;
    }
};

// Step 3: Create the Facade class and wrap the classes that implement the Interface 
class BankService {
    unordered_map<int, unique_ptr<IAccount>> *bankAccounts;    
    int index;

    public: 
    BankService(): index(0){ 
        bankAccounts = new unordered_map<int, unique_ptr<IAccount>>();    
    }

    int createNewAccount(string name, int amount, string type, int accountNo) {
        unique_ptr<IAccount> newAccount;	
        if(type.compare("current")) {	       
            newAccount.reset(new Current(amount));	
        }
      
        // Add to the unordered list
        pair<int, unique_ptr<IAccount>> toBeInserted = make_pair(accountNo, newAccount);
        bankAccounts->insert(toBeInserted);	
   
        return accountNo;
    }
};