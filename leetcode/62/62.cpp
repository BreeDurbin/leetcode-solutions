struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        unordered_map<pair<int,int>, long long, hash_pair> dp;
        return countPaths(m-1,n-1,dp);
    }

    int countPaths(int y, int x, unordered_map<pair<int,int>, long long, hash_pair> &dp){
        if(y==0 && x==0) return 1;
        auto pair = make_pair(y,x);
        if(dp[pair]) return dp[pair];
        dp[pair] = (y >= 0 ? countPaths(y-1,x,dp):0) + (x>=0 ? countPaths(y,x-1,dp):0);
        return dp[pair];
    }
};