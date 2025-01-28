class Solution {
private:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = 0;
                //search if not visited and a water node
                if(!vis[i][j] && grid[i][j]){
                    q.push({i, j});
                    vis[i][j] = true;
                    count += grid[i][j];
                }

                
                while(!q.empty()){
                    int row = q.front().first, col = q.front().second; 
                    q.pop();
                    
                    for(auto dir : dirs){
                        int nr = dir[0], nc = dir[1];
                        // skip this dir if out of bounds
                        if(row + nr < 0 || row + nr == m || col + nc < 0 || col + nc == n) continue;
                        // skip if visited or land
                        if(vis[row + nr][col + nc] || !grid[row + nr][col + nc]) continue;

                        vis[row + nr][col + nc] = true;
                        count += grid[row + nr][col + nc];
                        q.push({row + nr, col + nc});
                    }
                }

                ans = max(ans, count);
            }
        }



        return ans;

    }
};
