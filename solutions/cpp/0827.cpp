class Solution {

public:

    unordered_map<int, int> count;
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0, key = -1;
        int m = grid.size(), n = grid[0].size();

        //bfs to flag all island squares with key and store island size in map
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) bfs(grid, i, j, key--);
            }
        }

        //find connections
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check if can bridge 2 components
                if(grid[i][j] < 0) ans = max(ans, count[grid[i][j]]);
                //bridge 2 components
                if(grid[i][j] == 0){
                    int temp = 1;
                    unordered_set<int> used;
                    for(auto dir : dirs){
                        int ni = i + dir[0], nj = j + dir[1];
                        if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue; // out of bounds
                        if(used.find(grid[ni][nj]) == used.end()){ // if key has not been used then use it
                            temp += count[grid[ni][nj]];
                            used.insert(grid[ni][nj]);
                        }
                    }
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }

    void bfs(vector<vector<int>>& grid, int i, int j, int key){
        int m = grid.size(), n = grid[0].size();
        int sz = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = key; // flag current node with island key

        while(!q.empty()){
            int r = q.front().first, c = q.front().second; q.pop();

            for(auto dir : dirs){
                int nr = r + dir[0], nc = c + dir[1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue; // out of bounds
                if(grid[nr][nc] <= 0) continue; //water or visited
                if(grid[nr][nc] == 1){
                    q.push({nr,nc}); // land
                    grid[nr][nc] = key; // flag current node with island key
                    sz++; // increment size count
                }
            }

        }

        count[key] = sz;
    }
};
