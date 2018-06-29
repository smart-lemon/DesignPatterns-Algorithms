#include "./../../../Include/Common.h"

using namespace std;


// https://www.hackerrank.com/challenges/simple-array-sum


int simpleArraySum(int n, vector<int> ar) {
    int sum = 0;

    vector <int> :: iterator i;

    for (i = ar.begin(); i != ar.end(); ++i)
        sum += *i;
 
    return sum;
}