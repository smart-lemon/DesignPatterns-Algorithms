#include "./../../Include/Common.h"

using namespace std;

#include <sstream>
#include <vector>
#include <iterator>

// Declerations
std::vector<string> split(const string &s, char delim);


/*  
    ############################## Interpreter pattern ##############################

    ○→ Converts one representation of data into another. 
    ○→ It is used when you have multiple objectives that exist in a well defined, well understood domain.
       These objectives can be expressed as a simple language with simple grammar 
       e.g SQL statements, Simple addition-subtraction operations
    ○→ The interpreter codifies the grammer rules and syntax rules and executes commands writter in the
       language


    Components :- 
    1. Context:  Contains all information that will be interpreted. 
       →

    2. Abstract Expression: An abstract class that defines all methods that need to be implemented 
       to peform different conversions
        ○ This class receives the context that passes the global state of the interpreter
        ○ Each Expression performs a specific operations and possibly modifies
          the global state of the context to reflect that operation      
       → 

    3. Terminal Expression: (Or Concrete Expression) Performs specific conversions on different data type
        Terminal expression does not refer to any other expression. 
        ○ For example, in Maths a number is a terminal expression. 
          It is an independant symbol that does not relate to or operates on other 
          parts of the expresion 
       →

    4.  Non Terminal Expression : This is an expression that refers to one or more sub expressions in the 
         language   
         ○ For example. The plus operator related two sub expressions in the language.       

    5. Client: Holds a reference to the language context and initialized an Expression tree. 
         which is a hierarcy of terminal and non terminal expressions that define the syntax and
         grammer of the domain specific language    
       → testInterpreterPattern()

    6. Parser: Parses the language and builds an Expression tree from it     

*/


class Expression {
public:
    virtual int interpret() = 0;
};

//////////////////////
// Terminal Expression
//////////////////////
class Number : public Expression {

    int value;

public:

    Number(int num) {
        value = num;
    }   

    int interpret() {
        return value;
    }
};


//////////////////////
// Non Terminal Expression
//////////////////////
class Add : public Expression {
    
    Expression *lhs;
    Expression *rhs;
    
    public:

    Add(Expression *left, Expression *right) {  
        lhs = left;
        rhs = right;
    }   

    int interpret() {
        return lhs->interpret() + rhs->interpret();
    }
};


class Subtract : public Expression {
    
    Expression *lhs;
    Expression *rhs;
    
    public:

    Subtract(Expression *left, Expression *right) {  
        lhs = left;
        rhs = right;
    }   

    int interpret() {
        return lhs->interpret() -  rhs->interpret();
    }
};


//////////////////////
// Parser
//////////////////////
class Parser {
    Parser(string expression){

    }
};



// some helper functions for string splitting 
template<typename T>
void split(const string &s, char delim, T result) {
    stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


void testInterpreterPattern()
{

}