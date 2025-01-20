class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(),  m = mat[0].size();
        vector<int> rows(n), cols(m);
        
        unordered_map<int, pair<int,int>> reverse_lookup;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                reverse_lookup[mat[i][j]] = {i, j};
            }
        }


        for(int i=0; i < arr.size(); i++){
            int target_int = arr[i];
            if(++rows[reverse_lookup[target_int].first] == m) return i;
            if(++cols[reverse_lookup[target_int].second] == n) return i;
        }

        return -1;
    }
};
