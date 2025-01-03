class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0, cur = 0;
        int ans = 0;

        for(auto num : nums) total += num;
        for(int i=0; i<nums.size()-1; i++){
            cur += nums[i];
            long long right = total - cur;
            if(cur >= right) ans++;
        }

        return ans;
        
    }
};
