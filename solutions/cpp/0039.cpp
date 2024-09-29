class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> selected;
        backtrack(candidates, selected, ans, 0, 0, target);
        return ans;
    }

    void backtrack(vector<int>& candidates, vector<int>& selected, vector<vector<int>>& ans, int i, int total, int target){
        if(total == target){
            ans.push_back(selected);
            return;
        }
        if(i >= candidates.size() || total > target){
            return;
        }

        selected.push_back(candidates[i]);
        backtrack(candidates, selected, ans, i, total + candidates[i], target);
        selected.pop_back();
        backtrack(candidates, selected, ans, i + 1, total, target);
    }
};
