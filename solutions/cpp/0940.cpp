class Solution {
    const int MOD = 1'000'000'007;
public:
    int distinctSubseqII(string s) {

        vector<long long> dp(26, 0);
        long long total = 0;

        for(auto c : s){
            long long cur = (1 + total) % MOD;
            total = (total + cur - dp[c - 'a'] + MOD) % MOD;
            dp[c - 'a'] = cur;
        }

        return (int)(total % MOD);
    }
};
