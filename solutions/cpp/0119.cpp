class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=0; i<rowIndex; i++){
            ans.push_back(vector<int>(ans[i].size()+1));
            for(int j=0; j<ans[i].size(); j++){
                ans[i+1][j] += ans[i][j];
                ans[i+1][j+1] += ans[i][j];
            }
        }
        return ans[rowIndex];
    }
};
