class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), ans=0, count = 0;
        //map of counts to indexes
        unordered_map<int, int> cache;
        cache[0] = -1;
        
        for(int i=0; i<n; i++){
            count += (nums[i] == 1 ? 1 : -1);
            if(cache.find(count) != cache.end()){
                ans = max(ans, i - cache[count]);
            } else {
                cache[count] = i;
            }
        }
        
        return ans;
    }
};