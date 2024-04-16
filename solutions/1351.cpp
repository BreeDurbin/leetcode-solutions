class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        int cur = n-1;

        for(int i=0; i<m; i++){
            for(int j=cur; j>=0 && grid[i][j] < 0; j--) cur--;
            count += (n - (cur + 1));
        }

        return count;
    }
};