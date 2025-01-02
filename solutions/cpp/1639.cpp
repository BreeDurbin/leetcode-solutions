class Solution {
public:

    int MOD = 1'000'000'007;


    int numWays(vector<string>& words, string target) {
        
        int n = words[0].size();
        int m = target.size();

        vector<unordered_map<char,int>> freq(n);
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for (const string& word : words) {
            for (int i = 0; i < n; i++) {
                freq[i][word[i]]++;
            }
        }

        return solve(dp, freq, target, 0, n, 0, m);
    }

    int solve(vector<vector<int>>& dp, vector<unordered_map<char,int>>& freq, string& target, int i, int I, int k, int K){
        if(k == K) return 1; // return 1 if there is a match, 0 if no match
        if(i == I) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int ways = solve(dp, freq, target, i + 1, I, k, K) % MOD;
        if(freq[i].count(target[k])){
            long long count = freq[i][target[k]];
            ways = (ways + count * solve(dp, freq, target, i + 1, I, k + 1, K)) % MOD;
        }

        return dp[i][k] = ways;
    }
};
