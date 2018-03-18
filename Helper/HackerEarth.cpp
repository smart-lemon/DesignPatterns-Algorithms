#include "./../Include/CommonInc.h"

#include <iostream> 
#include <string>
#include <vector>

using namespace std;


vector<int> solve(int a0, int a1, int a2, int b0, int b1, int b2) {
    vector<int> ar; 
    int alice = 0, bob = 0;

    if(a0 > b0)
        alice++; 
    else if (a0 < b0)
        bob++;

    if(a1 > b1)
        alice++; 
    else if (a1 < b1)
        bob++;

    if(a2 > b2)
        alice++; 
    else if (a2 < b2)
        bob++;

    ar.push_back(alice);
    ar.push_back(bob);
    return ar;
}


int tmain() {

    return 0;
}