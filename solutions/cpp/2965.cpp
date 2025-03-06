class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> f;
        int m = grid.size(), n = grid[0].size();
        
        for(auto row : grid) for(auto cell : row) f[cell]++;
        
        int a = -1, b = -1;
        for(auto [key, val] : f) if(val > 1) a = key;
        for(int i=1; i<=m*m; i++) if(f[i] == 0) b = i;
        
        return {a, b};
    }
};
