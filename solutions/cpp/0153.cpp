class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = INT_MAX;
        if(r == 0) return nums[0];
        while(l <= r){
            int m = (l + r) / 2;
            ans = min(ans, nums[m]);
            if(nums[m] <= nums[r]) r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};
