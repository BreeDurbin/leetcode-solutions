class Solution {
public:

    int MOD = 1'000'000'007;

    int numberOfWays(int target, int pwr) {
        vector<int> pows;
        vector<vector<int>> memo(301, vector<int>(301, -1));

        for(int i=1; pow(i, pwr) <= target; i++){
            pows.push_back(pow(i, pwr));
        }

        return dfs(0, 0, target, pows, memo);
    }

    int dfs(int sum, int index, int target, vector<int>& pows, vector<vector<int>>& memo){
        if(sum == target) return 1;
        if(sum > target || index == pows.size()) return 0;
        if(memo[index][sum] != -1) return memo[index][sum];

        int skip = dfs(sum, index + 1, target, pows, memo);
        int use = dfs(sum + pows[index], index + 1, target, pows, memo);
        return memo[index][sum] = (skip + use) % MOD;
    }
};
