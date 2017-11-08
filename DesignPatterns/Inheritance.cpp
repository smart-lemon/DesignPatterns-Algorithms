
// Inheritance example

#include <iostream> 
#include <string>
using namespace std;

class Animal {

private : 
	string name;
	string sound;
	double height; 
	float weight;

public: 

    Animal(){
        // Base constructor
    }

	string getName(){ 
		return name;
	}

	void setName(string inName) {
		name = inName;
	}

	string getSound(){
		return sound;
	}

	void setSound(string inSound) {
			sound = inSound;
	}

	void setWeight(int inWeight) {

		if(inWeight <= 0) {
			cout << "Impossible!! " << endl; 
			return;
		}
		weight = inWeight;
	}
};

class Dog : public Animal {

public :
    Dog(){
        setSound("Bark!");
    }


    void digHole() {
        cout << "Dug a hole" << endl;
     }

};


class Cat : public Animal {
    
public :
    Cat(){
        setSound("Meow...");
    }
     
    void throwThingsOffTheTable() {
        cout << "Sounds of plates crashing!" << endl;
     }

};


void workWithAnimals(){

    // Dog
    Dog fido;
    fido.setName("Fido");

    cout << "Who's a good boy?!! " << fido.getSound() << " " << endl << fido.getName() << endl;

    fido.digHole();
    fido.setWeight(10);

    Cat shiroSan;
    shiroSan.setName("Shiro san");  
    shiroSan.throwThingsOffTheTable();

}
