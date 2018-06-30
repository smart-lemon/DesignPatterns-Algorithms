class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> hashmap; 
        
        // Put all elements in an hashset
        for(int i = 0; i < nums.size(); i++){
             hashmap.insert(make_pair(nums[i], i));
        }
        
        set<vector<int>> outputSet; 
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(i != j)
                {
                    int sum = nums[i] + nums[j];
                    if(hashmap.find(-sum) != hashmap.end())
                    {
                        if(hashmap[-sum] != i && hashmap[-sum] != j){
                            vector<int> line; 
                            line.push_back(nums[i]);
                            line.push_back(nums[j]);
                            line.push_back(sum);
                            sort(line.begin(), line.end());
                            outputSet.insert(line);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> output;
        set<vector<int>>:: iterator it;
        for( it = outputSet.begin(); it != outputSet.end(); ++it){
             output.push_back(*it);
        }

        return output;
    }
};