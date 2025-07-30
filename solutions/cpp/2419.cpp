class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int biggest_num = 0, n = nums.size();

        for(int num : nums) biggest_num = max(biggest_num, num);

        int max_len = 0, cur_len = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == biggest_num){
                cur_len++;
                max_len = max(cur_len, max_len);
            } else{
                cur_len = 0;
            }
        }
        return max_len;
    }
};
