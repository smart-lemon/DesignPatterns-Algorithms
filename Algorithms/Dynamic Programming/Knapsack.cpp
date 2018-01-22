#include "./../../Include/CommonInc.h"

using namespace std;

 
// A helper function that returns maximum of two integers
static int max(int a, int b) { return (a > b)? a : b; }

// data for knapsack
static int values[]  = { 60, 100, 120, 70 }; 
static int weights[] = { 10, 20, 30, 40 };

// Size - N
const static int N = 4;

// Capacity - C
const static int C = 150;


// Bottom up
void knapsack_1_0() 
{ 
    //v alue table having N + 1 rows and C + 1 columns
	int DP[N + 1][C + 1];

	// Row i = 0 with value 0 - because for weight 0, Result is 0
	for(int c = 0; c <= C; c++) {
		DP[0][c] = 0;
	}

	// Column with i = 0 with value 0
	for(int i = 0; i <= N; i++) {
		DP[i][0] = 0;
	}

	// For every item
	for(int i = 1; i <= N; i++) {
        // incrementally changing the knapsack size 
		for(int j = 1; j <= C; j++) {
            // if a weight is more than the allowed weight, that weight cannot be picked.
			if(weights[i] <= C) {
                                // i-th item is not used
				DP[i][j] = max( DP[i - 1][j], 
                                // i-th item is used
                                DP[i - 1][j - weights[i]] + values[i]); 
			} else {
				DP[i][j] = DP[i - 1][j];
			}
		}
    }
}


void testKnapsack() 
{

}