class Solution {
public:
    unordered_map<int,int> cache;
    
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeated = 0, missing = 0, n = grid.size(), sum = 0, nSquared = n*n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cache[grid[i][j]]++;
                if(cache[grid[i][j]] > 1){
                    //cout << "found repeat " << endl;
                    repeated = grid[i][j];
                }
                sum += grid[i][j];
            }
        }
        
        int properSum = nSquared*(nSquared+1)/2;
        missing = properSum - sum + repeated;
        //cout << "n: " << n << " nSquared: " << nSquared << " sum: " << sum << " proper sum: " << properSum << endl;
        return {repeated, missing};
    }
};