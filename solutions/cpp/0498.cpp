class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;

        int botleft = true;

        for(int j=0; j<m+n-1; j++){
            if(botleft){
                for(int i=0; i<=j; i++){
                    if(j-i >= m || i >= n) continue;
                    ans.push_back(mat[j-i][i]);
                }
            } else {
                for(int i=0; i<=j; i++){
                    if(i >= m || j-i >= n) continue;
                    ans.push_back(mat[i][j-i]);
                }
            }
            botleft = !botleft;
        }

        return ans;
    }
};
