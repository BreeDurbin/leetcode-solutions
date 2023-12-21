class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0; i<nums.size();i++){
            if(val_to_index.count(nums[i])){
                int dist = abs(val_to_index[nums[i]] - i);
                if(dist <= k){
                    return true;
                }
            }
            val_to_index[nums[i]] = i;
        }
        return false;
    }
    
private: 
    //map of vals to all associated keys 
    unordered_map<int, int> val_to_index;
};