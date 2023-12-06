class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = nums[0], cur_max_sum = 0, min_sum = nums[0], cur_min_sum = 0, total_sum = 0;
        for(auto &num : nums){
            cur_max_sum = max(num, cur_max_sum + num);
            max_sum = max(cur_max_sum, max_sum);
            cur_min_sum = min(num, cur_min_sum + num);
            min_sum = min(cur_min_sum, min_sum);
            total_sum += num;
        }
        return max_sum > 0 ? max(max_sum, total_sum - min_sum) : max_sum;
    }
};