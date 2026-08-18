class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        if(stoneValue.size() <= 1) return 0;

        vector<vector<int>> dp_l_r(stoneValue.size(), vector<int>(stoneValue.size(), -1));

        vector<int> prefix_sum(stoneValue.size() + 1, 0);

        for(int i = 0; i < stoneValue.size(); i++){
            prefix_sum[i + 1] = prefix_sum[i] + stoneValue[i];
        }

        function<int(int, int, vector<vector<int>>&, vector<int>&)> dfs;

        dfs = [prefix_sum, &dfs](int left, int right, vector<vector<int>>& dp, vector<int>& stones){
            if(dp[left][right] != -1) return dp[left][right];
            if(left == right) return dp[left][right] = 0;

            int ans = 0;

            for(int i = left; i<right; i++){
                int left_sum = prefix_sum[i + 1] - prefix_sum[left];
                int right_sum = prefix_sum[right + 1] - prefix_sum[i + 1];

                if (left_sum < right_sum) ans = max(ans, left_sum + dfs(left, i, dp, stones));

                else if (left_sum > right_sum) ans = max(ans, right_sum + dfs(i+1, right, dp, stones));

                else {
                    int max_of_both_sums = max(left_sum + dfs(left, i, dp, stones), right_sum + dfs(i+1, right, dp, stones));
                    ans = max(ans, max_of_both_sums);
                }
            }

            return dp[left][right] = ans;
        };


        return dfs(0, stoneValue.size() - 1, dp_l_r, stoneValue);
    }
};
