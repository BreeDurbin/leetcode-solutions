class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> max_column(n);
        fill(max_column.begin(), max_column.end(), -1);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = matrix[i][j];
                max_column[j] = max(max_column[j], matrix[i][j]);
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ans[i][j] == -1) ans[i][j] = max_column[j];
            }
        }
        
        return ans;
    }
};