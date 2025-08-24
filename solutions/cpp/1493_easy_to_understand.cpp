class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        bool is_spaced = false;
        int ans = 0;
        int first = 0;
        int second = 0;

        int i = 0;
        while(i < n){
            //expand to the right to fill first
            while(i < n && nums[i] == 1){
                first++;
                ans = max(ans, first + second);
                i++;
            }
            //if we hit zero, set spaced and move first to second
            second = first;
            first = 0;

            i++;
        }

        return ans == n ? ans - 1 : ans;
    }
};
