#include "./../../Include/Common.h"

using namespace std;

class Numbers {
    
private :
    int numberA;
    int numberB; 
    string calculationWanted;

public:
    Numbers(int numA, int numB, string calcWanted){
        numberA = numA;
        numberB = numB; 
        calculationWanted = calcWanted;
    }

    inline int getNumA(){ 
        return numberA; 
    }
    
    inline int getNumB(){ 
        return numberB; 
    }

    string getCalculationWanted(){
        return calculationWanted;
    }
};

// Interface 
class Chain {

protected: 
    Chain *nextChain;

public:
    void setNextChain(Chain *nextChain){
        this->nextChain = nextChain;
    }

    // Pure virtual function
    virtual void calculate(Numbers number) = 0;
};


class AddNumbers : public Chain {

 public:
    void calculate(Numbers request)
    {
        if(request.getCalculationWanted() == "add"){
            cout << "(A = " << request.getNumA() << ") + (B = " << request.getNumB();
            cout << ") = " << request.getNumA() + request.getNumB() << endl;
        } else if(nextChain) {
            cout << "Not qualified to handle " << request.getCalculationWanted() << endl;
            nextChain->calculate(request);
        } else {
            //End of the chain 
            cout << "Only supported operations are +, -, x, /" << endl;
        }
    }
};  


class SubtractNumbers : public Chain {
    
 public:

    void calculate(Numbers request)
    {
        if(request.getCalculationWanted() == "subtract"){
            cout << "(A = " << request.getNumA() << ") - (B = " << request.getNumB();
            cout << ") = " << request.getNumA() - request.getNumB() << endl;
        } else if(nextChain) {
            cout << "Not qualified to handle " << request.getCalculationWanted() << endl;
            nextChain->calculate(request);
        }  else  {
            //End of the chain 
            cout << "Only supported operations are +, -, x, /" <<    endl;
        }
    }
};  


class MultiplyNumbers : public Chain {
    
 public:
    void calculate(Numbers request)
    {
        if(request.getCalculationWanted() == "multiply"){
            cout << "(A = " << request.getNumA() << ") x (B = " << request.getNumB();
            cout << ") = " << request.getNumA() * request.getNumB() << endl;
     
        } else if(nextChain) {           
             cout << "Not qualified to handle " << request.getCalculationWanted() << endl;
             nextChain->calculate(request);
        } else  {
          //End of the chain 
          cout << "Only supported operations are +, -, x, /" <<    endl;
       }
    }
};  


class DivideNumbers : public Chain {
    
 public:
    void calculate(Numbers request)
    {
        if(request.getCalculationWanted() == "divide"){
            cout << "(A = " << request.getNumA() << ") / (B = " << request.getNumB();
            cout << ") = " << request.getNumA() / request.getNumB() << endl;
     
        } else if(nextChain) {
            cout << "Not qualified to handle " << request.getCalculationWanted() << endl;            
            nextChain->calculate(request);
       } else {    
            //End of the chain 
            cout << "Only supported operations are +, -, x, /" <<    endl;
        }
    }
};  

void testChainOfResponsibility()
{
    Chain *calcAdd = new AddNumbers();
    Chain *calcSub = new SubtractNumbers();
    Chain *calcMul = new MultiplyNumbers();
    Chain *calcDiv = new DivideNumbers();
    
    calcAdd->setNextChain(calcSub);
    calcSub->setNextChain(calcMul);
    calcMul->setNextChain(calcDiv);

    Numbers *requestOne = new Numbers(4, 2, "divide");
    calcAdd->calculate(*requestOne);

    Numbers *requestTwo = new Numbers(4, 2, "add");
    calcAdd->calculate(*requestTwo);
}