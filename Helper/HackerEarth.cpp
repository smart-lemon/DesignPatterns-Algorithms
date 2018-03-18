#include "./../Include/CommonInc.h"

#include <iostream> 
#include <string>
#include <vector>

using namespace std;


long aVeryBigSum(int n, vector<long> ar) {
   long sum = 0;
    vector <long> :: iterator i;
    for (i = ar.begin(); i != ar.end(); ++i)
        sum += *i;
    return sum;
}


int tmain() {

    return 0;
}