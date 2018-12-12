#include "./../../Include/Common.h"

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

// Concrete products 
// -----------------------------------------------
class BudgetChefsKnife : public Knife {
    public:
    void design() {
        cout << "Designing budget chefs knife" << endl;
    }
};

class BudgetSteakKnife : public Knife {
    public:
    void design() {
        cout << "Designing budget steak knife" << endl;
    }
};


class LuxuryChefsKnife : public Knife {
    public:
    void design() {
        cout << "Designing celebrity chefs knife" << endl;
    }
};

class LuxuryBreadKnife : public Knife {
    public:
    void design() {
        cout << "Designing premium bread knife" << endl;
    }
};
// -----------------------------------------------
// Factories
// -----------------------------------------------
class KnifeFactory {
    public:

    Knife *orderKnife(string knifeType) {
        Knife *knife;
        knife = createKnife(knifeType);

        knife->design();
        knife->sharpen();
        knife->polish();
        knife->package();

        return knife;
    }

    // The factory method
    virtual Knife *createKnife(string knifeType) = 0;
};

// Concrete creators 
// -----------------------------------------------
class BudgetKnifeFactory: public KnifeFactory {

    // Factory method
    Knife *createKnife(string knifeType) {

        if(knifeType.compare("steak"))
            return new BudgetSteakKnife();
        else if(knifeType.compare("chefs"))
            return new BudgetChefsKnife();
        else 
            return nullptr;
    }
};

class LuxuryKnifeFactory: public KnifeFactory {
    
    // Factory method
    Knife *createKnife(string knifeType) {

        if(knifeType.compare("bread"))
            return new LuxuryBreadKnife();
        else if(knifeType.compare("chefs"))
            return new LuxuryChefsKnife();
        else 
            return nullptr;
    }
};

// -----------------------------------------------



// -----------------------------------------------
    // Another example - A Coffee Machine making 
    // Different types of coffee
// -----------------------------------------------

// Product from which the concrete products will inherit from 
class Coffee {
protected:
	char _type[15];
public:
	Coffee(){
	}
	char *getType()	{
		return _type;
	}
};

// One concrete class
class Espresso : public Coffee {
public:
	Espresso() : Coffee() {
		strcpy(_type, "Espresso");
		cout << endl << "Making a cup of espresso" << endl;
		cout << "Grind and brew one scoop of espresso beans." << endl;
	}
};

// Another concrete class
class Cappuccino : public Coffee {
public:
	Cappuccino() : Coffee()	{
		strcpy(_type, "Cappuccino");
		cout << endl << "Making a cup of cappuccino" << endl;
		cout << "Grind and brew one scoop of espresso beans." << endl;
		cout << "Heat and foam milk." << endl;
	}
};

class CoffeeMakerFactory {
private:
	Coffee * _coffee;
public:
	Coffee * GetCoffee() {
		int choice;

		cout << "Select type of coffee to make: " << endl;
		cout << "1: Espresso" << endl;
		cout << "2: Cappuccino" << endl;
		cout << "Selection: ";
		cin >> choice;

		switch (choice)	{
            case 1:
                return new Espresso;
            case 2:
                return new Cappuccino;
            default:
                cout << "Invalid Selection" << endl;
                return nullptr;
		}
	}
};

int test_factory_method() {
	CoffeeMakerFactory coffeeMachine;
	Coffee *cup;
	cup = coffeeMachine.GetCoffee();

	cout << endl << "You had asked for a(n)" << cup->getType() << endl;
}