class Solution {
    int MOD = 1e9 + 7;

public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(1001, vector<int>(1001, 0));

        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i<=k; i++){
            long long row_sum = 0;

            for(int j = n-1; j >= 0; j--){
                row_sum = (row_sum + dp[i - 1][j + 1]) % MOD;
                int take = row_sum;
                int skip = dp[i][j+1] % MOD;

                dp[i][j] = (take + skip) % MOD;
            }
        }


        return dp[k][0];
    }
};
