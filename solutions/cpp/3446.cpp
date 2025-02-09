class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // center diagonal
        priority_queue<int> q;
        for(int i=0; i<n; i++){
            q.push(grid[i][i]);
        }
        for(int i=0; i<n; i++){
            grid[i][i] = q.top(); q.pop();
        }

        for(int i=1; i<n; i++){
            priority_queue<int> top_q;
            priority_queue<int, vector<int>, greater<int>> bot_q;
            for(int j=i; j<n; j++){
                top_q.push(grid[j][j-i]);
                bot_q.push(grid[j-i][j]);
            }
            for(int j=i; j<n; j++){
                grid[j][j-i] = top_q.top(); top_q.pop();
                grid[j-i][j] = bot_q.top(); bot_q.pop();
            }
        }
        return grid;
        
    }
};
