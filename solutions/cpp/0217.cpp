class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size();i++){
            if(cache[nums[i]]){
                return true;
            }
            cache[nums[i]]++;
        }
        return false;
    }
    
private: 
    unordered_map<int, int> cache;
};