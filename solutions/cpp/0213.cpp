class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size() - 1;
        int left = helper(nums, n);
        reverse(nums.begin(), nums.end());
        int right = helper(nums, n);
        return max(left, right);
    }

private:
    int helper(vector<int>& nums, int n){
        int prev1=0, prev2=0;
        for(int i=0; i<n; i++){
            int cur = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = cur;
        }
        return max(prev1, prev2);
    }
};