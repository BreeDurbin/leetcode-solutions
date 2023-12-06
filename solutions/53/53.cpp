class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = INT_MIN, current_sum = 0;
        for(auto &num : nums){
            current_sum = max(num, current_sum + num);
            best_sum = max (current_sum, best_sum);
        }
        return best_sum;
    }
};