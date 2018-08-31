#include "./../../../Include/Common.h"

using namespace std;

/*
    Get a bit
*/
bool getBit(int num, int i) {
    return ((num & (1 << i)) != 0);
}

/*
    Set a bit
*/
int setBit(int num, int i) {
    return (num | (1 << i));
}

/*
    Clear a bit
*/
int clearBit(int num, int i) {
    int mask = ~(1 << i);
    return (num & mask);
}

/*
    Clears MSB to i (including i)
*/
int clearBitFromMsbToI(int num, int i){
    int mask = ~(1 << i) - 1;
    return num & mask;
}


/*
    Clears i to LSB (including i)
*/
int clearBitFromIToILsb(int num, int i){
    int mask = (-1 << (i + 1));
    return num & mask;
}
