#include "./../../Include/CommonInc.h"

using namespace std;

// Home grown helpers
static long long max(long long a, long long b) { return (a > b)? a : b; }

long long power(long long base, unsigned int exp)
{
    long long temp;
    if(exp == 0)
        return 1;
    temp = power(base, exp/2);
    if (exp % 2 == 0)
        return temp * temp;
    else
        return base * temp * temp;
}


int getLengthOf(long long number) {

    int count = 0;

    while(number) {
        count++;
        number = number/10;
    }
    return count;
}


long long karatsuba_multiply(long long x, long long y){
     
     int xLen = getLengthOf(x); 
     int yLen = getLengthOf(y);

    if(xLen == 1 || yLen == 1)
        return x * y;

    int n = max(x, y);

    int n_by_2 = (n / 2) + (n % 2);

    long long multiplier = power(10, n_by_2);
   
    long long b = x/multiplier; 
    long long a = x - (b * multiplier); 
    long long d = y/multiplier; 
    long long c = y - (d * multiplier); 

    long long ac = karatsuba_multiply(a, c);
    long long bd = karatsuba_multiply(b, d);

    long long aplusb_x_cplusd = karatsuba_multiply(a + b, c + d);

}