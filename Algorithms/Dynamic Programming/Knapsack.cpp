#include "./../../Include/CommonInc.h"

using namespace std;

 
// A helper function that returns maximum of two integers
static int max(int a, int b) { return (a > b)? a : b; }

// data for knapsack
static int values[]  = { 60, 100, 120 }; 
static int weights[] = { 10, 20, 30 };

// Size - N
const static int N = 3;

// Capacity - C	
const static int C = 50	;


// Bottom up 
int knapsack_1_0() 
{ 
    // DP array contains the best possible value -  having N + 1 rows and C + 1 columns
	int DP[N + 1][C + 1];

	// Row i = 0 with value 0 - because for capacity 0, Result is 0
	for(int c = 0; c <= C; c++) {
		DP[0][c] = 0;
	}

	// Column with c = 0 with value 0  - no capacity so you cant pack anything
	for(int i = 0; i <= N; i++) {
		DP[i][0] = 0;
	}

	// For every item
	for(int i = 1; i <= N; i++) {
        // Incrementally changing the knapsack size 
		for(int j = 1; j <= C; j++) {
            // If a weight is more than the allowed weight, that weight cannot be picked.
			if(weights[i] <= j) {
                                // i-th item is not used
				DP[i][j] = max( DP[i - 1][j], 
                                // i-th item is used, j - weights[i] is the remaining capacity after usingg i-th item
                                DP[i - 1][j - weights[i]] + values[i]); 
			} else {
				DP[i][j] = DP[i - 1][j];
			}
		}
    }

	return DP[N][C];
}


int recursiveKnapsack(int i, int c)
{
	// If 0 items or capacity, return 0 as value
	if(i == 0 || c == 0)
		return 0;

	if(weights[i] > c)
	 	return recursiveKnapsack(i - 1, c);

	return max(recursiveKnapsack(i - 1, c), recursiveKnapsack(i - 1, c - 1) + values[i]);
}

void testKnapsack() 
{
    cout << "Bottom up - Knapsack 1-0 " << knapsack_1_0() << endl;
	cout << "Recursive - Knapsack 1-0 " << recursiveKnapsack(N, C) << endl;
}