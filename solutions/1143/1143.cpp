class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        if(a==b) return a.size();
        vector<vector<int>> memo(a.size()+1, vector<int>(b.size()+1, 0));
        for(int i=a.size()-1; i>=0;i--){
            for(int j=b.size()-1; j>=0; j--){
                if (a[i] == b[j]){
                    memo[i][j] = 1 + memo[i+1][j+1];
                }
                else{
                    memo[i][j] = max(memo[i+1][j], memo[i][j+1]);
                }
            }
        }

        return memo[0][0];
    }
};