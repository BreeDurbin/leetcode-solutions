
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size(), n = t2.size();

        vector<vector<int>> lcs(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                lcs[i][j] = t1[i-1] == t2[j-1] ? 1 + lcs[i-1][j-1] : max(lcs[i-1][j], lcs[i][j-1]);
            }
        }

        return lcs[m][n];
    }
};
