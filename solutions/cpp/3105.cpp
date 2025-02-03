class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cur_len = 1, ans = 0, m = nums.size();
        if(m == 1) return 1;
        
        for(int i=1; i<m; i++){
            if(nums[i] > nums[i-1]) cur_len++;
            else cur_len = 1;
            ans = max(ans, cur_len);
        }

        cur_len = 1;

        for(int i=1; i<m; i++){
            if(nums[i] < nums[i-1]) cur_len++;
            else cur_len = 1;
            ans = max(ans, cur_len);
        }

        return ans;
    }
};
