class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<int> row_sums(m);
        
        for(int i=0; i<n; i++){
            int cur = 0;
            for(int j=0; j<m; j++){
                row_sums[j] += grid[j][i];
                cur += row_sums[j];
                if(cur <= k) ans++;
                else continue;
            }
        }
        
        return ans;
    }
};