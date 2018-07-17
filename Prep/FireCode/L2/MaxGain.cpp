
// Swap position a with b in an array of integer numbers
int max_gain(int arr[], int sz)
{
    int max = 0, min = 1 << 31 - 1;
    int index_max = -1, index_min = -1; 
    for(int i = 0; i < sz; i++){
        
        if(min > arr[i]) {
            min = arr[i];
            index_min = i;
        }
            
        if(max < arr[i]){
            max = arr[i];
            index_max = i;
        }
    }
    
    if(index_max < index_min)
        return 0;
    return max - min;    
}