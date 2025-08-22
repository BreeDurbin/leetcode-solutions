class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int min_x = INT_MAX, max_x = -1, min_y = INT_MAX, max_y = -1;

        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                if(grid[x][y]){
                    min_x = min(min_x, x);
                    max_x = max(max_x, x);
                    min_y = min(min_y, y);
                    max_y = max(max_y, y);
                }
            }
        }

        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};
