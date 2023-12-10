class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, sum = 0, smallest_size = INT_MAX;
        for(int right = 0; right<nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                sum -= nums[left];
                smallest_size = min(right + 1 - left, smallest_size);
                left++;
            }
        }

        return smallest_size != INT_MAX ? smallest_size : 0;
    }
};