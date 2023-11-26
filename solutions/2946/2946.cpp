class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for(int i=0; i<mat.size(); i++){
            if(i % 2 == 1){
                reverse(mat[i].begin(), mat[i].end());
            }
            for(int j=0; j<mat[i].size(); j++){
                int n = mat[i].size();
                if(mat[i][j] != mat[i][(j+k)%n]){
                    return false;
                }
            }
        }
        return true;
    }
};