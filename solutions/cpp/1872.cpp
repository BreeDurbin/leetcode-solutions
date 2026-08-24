class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> dp(n, 0);
        vector<int> prefix_sums(n , 0);


        prefix_sums[0] = stones[0];

        for(int i = 1; i < n; i++) {
            prefix_sums[i] = stones[i] + prefix_sums[i - 1];
        }

        dp[n - 1] = prefix_sums[n - 1];

        for(int i=n - 2; i>0; i--){
            dp[i] = max(dp[i+1], prefix_sums[i]- dp[i+1]);
        }

        return dp[1];
    }
};
