

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