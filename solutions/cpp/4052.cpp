class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        for(int i=0; i<n; i++){
            //left rotate 
            int shift = rowShift[i] % n;

            rotate(grid[i].begin(), grid[i].begin() + shift, grid[i].end());
        }

        
        for(int i=0; i<n; i++){
            vector<int> column(n, 0);

            // for each col copy each cell into temp column, 
            for(int j=0; j < n; j++){
                column[j] = grid[j][i];
            }

            int shift = colShift[i] % n;

            rotate(column.begin(), column.begin() + shift, column.end());

            // copy col back into grid

            for(int j=0; j < n; j++){
                grid[j][i] = column[j];
            }
        }

        return grid;
    }
};
