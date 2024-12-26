class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n); // [index, sum] -> count
        return memoization(nums, dp, target, 0, 0);
    }

    // et tu
    int memoization(vector<int>& nums, vector<unordered_map<int,int>>& dp, int target, int index, int sum){
        if(index == nums.size()){
            return sum == target;//base case , return 0 on a mismatch and 1 on a match
        }
        if(dp[index].count(sum)) return dp[index][sum];
        int left = memoization(nums, dp, target, index + 1, sum + nums[index]);
        int right = memoization(nums, dp, target, index + 1, sum - nums[index]);
        return dp[index][sum] = left + right;
    }
};
