class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;;
        vector<vector<int>> max_sq_sz(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) continue;
                if(i == 0 || j == 0) max_sq_sz[i][j] = matrix[i][j];
                else max_sq_sz[i][j] = 1 + min({max_sq_sz[i-1][j], max_sq_sz[i-1][j-1], max_sq_sz[i][j-1]});
                ans += max_sq_sz[i][j];
            }
        }

        return ans;
    }
};
