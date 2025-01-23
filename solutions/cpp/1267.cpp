class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> row_count(m), col_count(n);

        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1)){
                    ans++;
                }
            }
        }

        return ans;
    }
};
