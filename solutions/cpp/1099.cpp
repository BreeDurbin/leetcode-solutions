class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int ans = INT_MIN, left = 0, right = nums.size()-1;
        if(right == 0) return -1;
        sort(nums.begin(), nums.end());

        while(left < right){
            int temp = nums[left] + nums[right];
            if(temp >= k){
                right--;
            }
            else {
                left++;
                ans = max(ans, temp);
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};
