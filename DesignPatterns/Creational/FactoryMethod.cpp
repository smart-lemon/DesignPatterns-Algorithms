#include "./../../Include/Common.h"
#include <string>

using namespace std;
// -----------------------------------------------
// Products of the factory
// -----------------------------------------------
class Knife {
    public: 
        inline void sharpen() {
             cout << "Sharpening" << endl;
        }
        inline void polish() {
             cout << "Polishing" << endl;
        }
        inline void package() {
             cout << "Packaging" << endl;
        }

        virtual void design() = 0;
};

// Concrete objects 
class BudgetSteakKnife : public Knife {
    public:
    void design() {
        cout << "Designing budget steak knife" << endl;
    }
};

class BudgetChefsKnife : public Knife {
    public:
    void design() {
        cout << "Designing budget chefs knife" << endl;
    }
};

// -----------------------------------------------
// Factories
// -----------------------------------------------
class KnifeStore {
    public:

    Knife *orderKnife(string knifeType){
        Knife *knife;
        knife = createKnife(knifeType);

        knife->sharpen();
        knife->polish();
        knife->package();

        return knife;
    }

    // The factory method
    virtual Knife *createKnife(string knifeType) = 0;
};

class BudgetKnifeStore: public KnifeStore {

    Knife *createKnife(string knifeType) {
        if(knifeType.compare("steak"))
            return new BudgetSteakKnife();
        else if(knifeType.compare("chefs"))
            return new BudgetChefsKnife();
    }
};

// -----------------------------------------------
void testFactoryMethod(){
    
}