#include "./../H/InterviewBit.h"
#include <math.h>       /* sqrt */
using namespace std;

/*
    Given an even number (greater than 2), 
    return two prime numbers whose sum will be equal to given number.

    https://www.interviewbit.com/problems/prime-sum/
*/


int isPrime(int n) {
    if (n < 2) return 0;
        // Calculate the sqrt
        int upperLimit = (int)(sqrt(n));
        for (int i = 2; i <= upperLimit; i++) {
            if (n % i == 0) return 0;
        }
     return 1;
}


vector<int> Solution :: primesum(int n) {
    for(int i = 1; i < n; i++ ){
        if(isPrime(i) && isPrime(n - i)){
            return vector<int>{i, n - i};
        }
    }
    return vector<int>{};
}
