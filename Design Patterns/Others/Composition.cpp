#include <iostream> 
#include <string>
#include <stdio.h>
using namespace std;

// Base Entree class
class Entree {
protected:
	char _entree[10];
public:
	const char *getEntree()	{
		return _entree;
	}
};


// Base Side class
class Side {
protected:
	char _side[10];
public:
	char *getSide()	{
		return _side;
	}
};

class Drink {
protected:
	char _drink[10];
public:
	Drink()  {
		cout << "\n Fill cup with soda" << endl;
		strcpy(_drink, "soda");
	}
	char *getDrink() {
		return _drink;
	}
};

// Complex MealCombo object that contains an Entree, a Side and a Drink object
class MealCombo {
private:
	Entree * entree;
	Side * side;
	Drink * drink;
	char _bag[100];
public:
	MealCombo(const char *type)	{
		sprintf(_bag, "/n %s meal combo:", type);
	}

	void setEntree(Entree *e) {
		entree = e;
	}

	void setSide(Side *s){
		side = s;
	}

	void setDrink(Drink *d)	{
		drink = d;
	}

	const char *openMealBag() {
		sprintf(_bag, "%s %s, %s, %s", _bag, entree->getEntree(), 
                                             side->getSide(), 
                                             drink->getDrink());
		return _bag;
	}
};