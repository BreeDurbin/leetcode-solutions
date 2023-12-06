class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        
        unordered_map<int,int> strength;
        int biggest_team = 0;
        
        for( int i = 0; i < grid.size(); ++i ) {
            for(int j=0; j < grid[0].size(); j++){
                strength[i] += grid[i][j];
                biggest_team = strength[biggest_team] > strength[i] ? biggest_team : i;
            }
        }

        return biggest_team;
    }
};