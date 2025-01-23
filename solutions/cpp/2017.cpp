class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top_sum = 0, bottom_sum = 0, ans = LONG_LONG_MAX;

        for(auto cell : grid[0]){
            top_sum += cell;
        }

        for(int i=0; i<n; i++){
            top_sum -= grid[0][i];
            ans = min(ans, max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }

        return ans;
    }
};
