class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right, piv, ans;
        for(auto n : nums){
            if(n < pivot) left.push_back(n);
            else if(n == pivot) piv.push_back(n);
            else right.push_back(n);
        }
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), piv.begin(), piv.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
