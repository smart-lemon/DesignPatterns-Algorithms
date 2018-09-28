#include "./../H/InterviewBit.h"
#include <math.h>       /* sqrt */
using namespace std;

/*
    Given a number N, find all factors of N.
*/

vector<int> Solution :: allFactorsTle(int A) {
    int number = A; 

    vector<int> result; 
    int i = 1;

    while(number > 0){
        number = A; 
        if(i % A == 0) 
            result.push_back(i);
        i++;
        number = number / A; 
    }
    return result;
}



vector<int> Solution :: allFactors(int A) {

    vector<int> result;
    int n = A; 
    for (int i=1; i <= sqrt(n); i++) 
    { 
        if (n % i == 0) 
        { 
            // If divisors are equal, add to result once only
            if (n/i == i) 
               result.push_back(i);
  
            else {
                result.push_back(i);
                result.push_back((int) A/i);
            } 
        } 
    } 

    // Interview bit cannot handle unsorted arrays
    sort(result.begin(), result.end());
    return result;
}


 // Note that this loop runs till square root 
    