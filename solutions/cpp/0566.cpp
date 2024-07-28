class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() != r*c) return mat;
        vector<vector<int>> out(r, vector<int>(c));
        int index = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                out[index / c][index % c] = mat[i][j];
                index++;
            }
        }
        return out;
    }
};