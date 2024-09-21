class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(1, temp, ans, k, n);

        return ans;
    }

    void backtrack(int i, vector<int> combination, vector<vector<int>>& ans, int k, int n){
        if(combination.size() == k) {
            ans.push_back(combination);
            return;
        }

        for(; i <= n; i++){
            combination.push_back(i);
            backtrack(i+1, combination, ans, k, n);
            combination.pop_back();
        }
    }
};
