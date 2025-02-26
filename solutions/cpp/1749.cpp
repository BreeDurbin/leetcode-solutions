class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int m = nums.size();
        
        int cur_min = 0, cur_max = 0, ans = 0;
        for(int i=0; i<m; i++){
            cur_min = min(0, cur_min + nums[i]);
            cur_max = max(0, cur_max + nums[i]);
            ans = max(ans, cur_max - cur_min);
        }

        return ans;
    }
};
