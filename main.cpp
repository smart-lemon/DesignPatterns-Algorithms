

#include "./Include/CommonInc.h"

using namespace std;

void testProgram();

int main() 
{
	cout << "Hello World" << "\n";

	
	// testProgram();
  	return 0; 
}

void testProgram()
{
	int which = 0;
	cout << "Which program do you want to try? " << endl << endl;

	cout << "1. Inheritance " << endl << endl;
	cout << " ===== Behavioural Design Patterns =====" << endl;
	cout << "2. Chain of Responsibility" << endl;
	cout << "3. Command Pattern" << endl;
	

	cout << endl;
	cin >> which;

	switch(which) {
		case 1: 
			workWithAnimals();		
		break;
		case 2: 
			testChainOfResponsibility();		
		break;
		case 3: 
			testCommandPattern();		
		break;
		
	}
}