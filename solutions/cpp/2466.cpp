class Solution {
    int MOD = 1'000'000'007;
    unordered_map<int,int> dp;

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(0, low, high , zero, one) % MOD;        
    }

    int solve(int total, int low, int high, int zero, int one){
        if(total > high) return 0;
        if(dp.find(total) != dp.end()) return dp[total];
        int in_bound = (total >= low && total <= high) ? 1 : 0;
        int zeroes = solve(total + zero, low, high , zero, one);
        int ones = solve(total + one, low, high , zero, one);
        return dp[total] = (in_bound + zeroes + ones) % MOD;
    }
};
