#include "./../H/InterviewBit.h"
#include <math.h>       /* sqrt */
using namespace std;


/*
    Given a number N, verify if N is prime or not.

    https://www.interviewbit.com/problems/verify-prime/
*/
int Solution :: isPrime(int n) {
    if (n < 2) return 0;
        // Calculate the sqrt
        int upperLimit = (int)(sqrt(n));
        for (int i = 2; i <= upperLimit; i++) {
            if (n % i == 0) return 0;
        }
     return 1;
}
