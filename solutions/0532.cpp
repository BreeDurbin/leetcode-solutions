class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<long, int> cache;
        
        for(int i=0; i<nums.size(); i++) cache[nums[i]]++;
        
        for(auto v : cache){
            // if the diff exists in cache for an index which is not i increment count
            if(k > 0 && cache.find(v.first + k) != cache.end()){
                count++;
            } else if(k == 0 && v.second > 1){
                count++;
            }
        }
        
        return count;
        
    }
};