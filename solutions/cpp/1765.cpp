class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<int> q;
        vector<vector<int>> ans(m, vector<int>(n, 0));

        vector<pair<int,int>> dirs({{0,-1}, {0, 1}, {1, 0}, {-1, 0}});

        //0 land cell
        //1 water cell
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    q.push(i * n + j);
                }
                else{
                    ans[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            
            int row = q.front() / n, col = q.front() % n;
            q.pop();

            for(auto dir : dirs){
                int next_row = row + dir.first, next_col = col + dir.second;

                if(next_row >= 0 && next_row < m &&
                   next_col >= 0 && next_col < n &&
                   ans[next_row][next_col] == -1
                ){
                    ans[next_row][next_col] = ans[row][col] + 1;
                    q.push(next_row * n + next_col);
                }
            }
        }

        return ans;

    }
};
