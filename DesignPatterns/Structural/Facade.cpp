#include "./../../Include/Common.h"
#include <string>
#include <unordered_map>

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

// Step 3: Create the Facade class and wrat the classes that implement the Interface 
class BankService {
    unordered_map<int, unique_ptr<IAccount>> bankAccounts;

    public: 
    BankService() { 

    }

    int createNewAccount(string name, int amount, string type) {
        IAccount *newAccount;

        if(type.compare("current")) {
             newAccount = new Current(amount);
        }
        if(type.compare("savings")) {
            newAccount = new Savings(amount);
        }
        if(type.compare("investment")) {
             newAccount = new Investments(amount);
        }

        if(newAccount != nullptr){
            // Add to the unordered list
        }
    }
};