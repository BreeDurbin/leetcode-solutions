class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(grid, 0, 0, dp);
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        if(r == grid.size() || c == grid[0].size() || grid[r][c] == 1) return 0;
        if(r == grid.size() - 1 && c == grid[0].size() - 1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = dfs(grid, r+1, c, dp) + dfs(grid, r, c+1, dp);
    }
};
