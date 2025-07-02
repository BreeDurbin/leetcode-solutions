class Solution {
public:
    int numDistinct(string s, string t) {
        int i = 0, j = 0, m = s.size(), n = t.size();

        vector<vector<int>> memo = vector(m, vector<int>(n, -1));

        function<int(int,int)> f = [&](int i, int j){
            if(j == n) return 1;
            if(i == m) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = s[i] == t[j] ? f(i+1, j+1) + f(i+1, j) : f(i+1, j);
        };

        return f(0,0);
    }
};
