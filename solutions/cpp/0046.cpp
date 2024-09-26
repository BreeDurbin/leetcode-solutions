class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> used;
        backtrack(used, ans, nums);

        return ans;
    }

    void backtrack(vector<int>& used, vector<vector<int>>& ans, vector<int>& nums){
        if(used.size() == nums.size()){
            ans.push_back(used);
            return;
        }

        for(auto num : nums){
            if(find(used.begin(), used.end(), num) == used.end()){
                used.push_back(num);
                backtrack(used, ans, nums);
                used.pop_back();
            }
        }
    }
};
