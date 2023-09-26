class Solution {
public:
    unordered_map<int,int> memo;
    const long mod = 1e9+7;
    int numTilings(int n) {
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 5;
        return numTilingsRec(n) % mod;
    }
    long long numTilingsRec(int n) {
        if(memo[n]) return memo[n];
        else {
            memo[n] = 2*numTilingsRec(n-1) % mod + numTilingsRec(n-3) % mod;
        }
        return memo[n];
    }
};