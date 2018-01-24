

#include "./Include/CommonInc.h"

using namespace std;

void testProgram();

const int DESIGN_PATTERNS = 1;
const int ALGORITHMS = 2; 
const int DATA_STRUCTURES = 3; 

// →  ⇨ ➡ ⇒ ⟹ ►
// 	• ○  

int main() 
{
	cout << "Hello World" << "\n";
	
	// testProgram();
  	return 0; 
}


int selectCourse() {
	int what = 0;
	cout << "Select a course name" << endl;
	cout << "1. Design Patterns" << endl << "2. Algorithms" << endl << "3. DS" << endl;
	cin >> what; 

	return what;
}

void selectDesignPattern(){
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

void testProgram()
{
	int which = 0;

	which =  selectCourse();
	switch(which) {
		case DESIGN_PATTERNS: 
			selectDesignPattern();		
		break;
	}
}