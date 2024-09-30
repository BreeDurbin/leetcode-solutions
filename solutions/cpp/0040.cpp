class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, cur, ans, 0, 0, target);
        return ans;
    }

    void backtrack(vector<int>& candidates, vector<int> cur, vector<vector<int>>& ans, int i, int total, int target){
        if(total == target){
            ans.push_back(cur);
            return;
        }
        if(total > target || i >= candidates.size()){
            return;
        }

        cur.push_back(candidates[i]);
        backtrack(candidates, cur, ans, i + 1, total + candidates[i], target);
        cur.pop_back();

        while(i + 1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        backtrack(candidates, cur, ans, i + 1, total, target);
    }
};
