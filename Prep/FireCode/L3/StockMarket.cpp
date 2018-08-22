
//  Max Profit in a Stock Market 
int max_profit(int prices[], int sz)
{
    int min_index = 0; 
    int best    = 0;
    int profits = 0;
    
    int i = 1; 
    while (i < sz) {
        if(prices[i] > prices[i - 1]){
            int diff = prices[i] - prices[i - 1];
            profits += diff; 
        }
        i++;
    }

    return profits;
}