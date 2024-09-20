class Solution {

    set<pair<int,int>> vis;

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i=0;i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && vis.find({i, j}) == vis.end()){
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }

private: 
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(vis.find({row, col}) != vis.end()) return;
        vis.insert({row, col});

        if(row + 1 < grid.size() && grid[row][col] == '1') dfs(grid, row + 1, col);
        if(col + 1 < grid[0].size() && grid[row][col] == '1') dfs(grid, row, col + 1);
        if(row - 1 >= 0 && grid[row][col] == '1') dfs(grid, row - 1, col);
        if(col - 1 >= 0 && grid[row][col] == '1') dfs(grid, row, col - 1);

    }
};
