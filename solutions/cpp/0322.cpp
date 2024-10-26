class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount);
        return solve(coins, amount, dp);
    }

    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount - 1]) return dp[amount-1];
        int curMin = INT_MAX;
        for(auto coin : coins){
            int cur = solve(coins, amount - coin, dp);
            if(cur >= 0 && cur < curMin) curMin = 1 + cur;
        }
        dp[amount - 1] = (curMin == INT_MAX) ? -1 : curMin;
        return dp[amount-1];
    }
};
