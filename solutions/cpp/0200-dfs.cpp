
class Solution {

    set<pair<int,int>> vis;

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i=0;i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis.contains({i, j})){
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }

private: 
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(vis.contains({row, col})) return;
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        vis.insert({row, col});
        if(grid[row][col] == '0') return;

        dfs(grid, row + 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row - 1, col);
        dfs(grid, row, col - 1);

    }
};
