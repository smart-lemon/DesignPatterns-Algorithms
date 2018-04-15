#include "./../../Include/Common.h"

using namespace std;

/*
    Karatsuba multiplication : recursively multiplies two numbers using a modified version of the Eulers method
*/


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

    if(xLen < 2 || yLen < 2)
        return x * y;

    int n = max(xLen, yLen);

    int n_by_2 = (n / 2) + (n % 2);

    long long multiplier = power(10, n_by_2);
   
    long long a = x/multiplier; 
    long long b = x - (a * multiplier); 

    long long c = y/multiplier; 
    long long d = y - (c * multiplier); 

    long long ac = karatsuba_multiply(a, c);
    long long bd = karatsuba_multiply(b, d);

    long long aplusb_x_cplusd = karatsuba_multiply(a + b, c + d); 

    return bd + ((aplusb_x_cplusd - ac - bd) * multiplier) + 
           (ac * (long long)(power(10, 2 * n_by_2)));        
}

void testKaratsuba() {
    long x = 56789;
    long y = 1234;

    long long ret = karatsuba_multiply(x, y);

    cout << "x times y = " << x << " x " << y << " = " << ret; 
    cout << endl;

}