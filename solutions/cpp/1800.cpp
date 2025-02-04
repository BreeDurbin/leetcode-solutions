class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], cur = nums[0], n = nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) cur += nums[i];
            else cur = nums[i];
            ans = max(ans, cur);
        }

        return ans;
    }
};
