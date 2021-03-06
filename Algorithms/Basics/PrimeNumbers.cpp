#include "./../../Include/Common.h"

using namespace std;
    
/* 
    Finds a prime number. A prime number is a positive integer, which is divisible on 1 and itself. 
    Runtime: O(n)
*/ 

// Sieve of Eratosthenes
bool isPrime(int n){
    if (n < 2) return 0;
        // Calculate the sqrt
        int upperLimit = (int)(sqrt(n));
        for (int i = 2; i <= upperLimit; i++) {
            if (n % i == 0) return 0;
        }
     return 1;
}

// AKS 
bool isPrimeAks(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if ((n % i == 0) || (n % (i + 2) == 0))
           return false;

    return true;
}

//  Coprime integers are a set of integers that have no common divisor other than 1 or -1.
void areCoPrimes(){

}