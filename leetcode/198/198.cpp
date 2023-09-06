class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int n = nums.size();
        int prev1=max(nums[2] + nums[0],nums[1]), prev2=nums[1], prev3=nums[0];
        for(int i = 3; i < n; i++){
            int cur = nums[i] + max(prev2, prev3);
            prev3=prev2;
            prev2=prev1;
            prev1=cur;
        }
        return max(prev1, prev2);
    }
};