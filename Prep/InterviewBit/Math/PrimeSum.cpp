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

vector<int> Solution :: primesum(int N) {

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    
    // Sieve of Erastothenes
    for(int i = 2; i <= N; i++) {
        if (!is_prime[i]) continue;
        if (i > N / i) break;
        for (int j = i * i; j <= N; j += i) 
            is_prime[j] = false;
    }
    
    for(int i = 2; i <= N; ++i) {
        if(is_prime[i] && is_prime[N - i]) {
            vector<int> ans;
            ans.push_back(i);
            ans.push_back(N - i);
            return ans;
        }
    } 

    vector<int> ans; 
    return ans;
}
