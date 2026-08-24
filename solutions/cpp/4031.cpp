class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int left = lower;

        for(int right : nums){
            if(right < left) continue;
            if(right > upper) break;

            if(right > left){
                ans.push_back({left, right - 1});
            }

            left = right + 1;
        }

        if(left <= upper){
            ans.push_back({left, upper});
        }


        return ans;
    }
};
