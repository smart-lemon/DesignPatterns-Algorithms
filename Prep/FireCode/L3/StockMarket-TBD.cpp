// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
int max_profit(int prices[], int sz)
{
    int min_index = 0; 
    int best = 0;
    
    int profits = 0;
    
    int i = 1; 
    while (i < sz) {
        if(prices[i] > prices[min_index]){
            int diff = prices[i] - prices[min_index];
            if(best < diff){
                best = diff;
            }
        } else {
            profits += best; 
            min_index  = i;
        }
        i++;
    }
    
    return profits;
}