#include "./../Include/CommonInc.h"

#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int simpleArraySum(int n, vector<int> ar) {
    int sum = 0;

    vector <int> :: iterator i;

    for (i = ar.begin(); i != ar.end(); ++i)
        sum += *i;
 
    return sum;
}


int tmain() {

    vector<int> ar(6);

   for (int i = 1; i <= 5; i++)
        ar.push_back(i);
 

    int sum = simpleArraySum(6, ar);

    cout << sum;

    return 0;
}