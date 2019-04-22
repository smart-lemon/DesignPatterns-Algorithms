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
int clearBitFromIToLsb(int num, int i){
    int mask = (-1 << (i + 1));
    return num & mask;
}


/*
    Returns the position of the rightmost '1' bit 
    00101100 -> 00000100
*/
unsigned int valueOfRightmostBit(unsigned int x) {
    return x & ~(x - 1);
}


/*
    Clears the rightmost '1' bit 
    00101100 -> 00101000
*/
unsigned int clearTheRightmostBit(unsigned int x) {
    return x ^ valueOfRightmostBit(x);
}

/*
    Binary printing helper
*/

void printBinary(int number) {
    if (number) {
        printBinary(number >> 1);
        (number & 1) ? cout << '1' : cout << '0';
    }
    cout << endl;
}