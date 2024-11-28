class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < nums[mid + 1]){ // increasing
                left = mid + 1;
            } else { // decreasing
                right = mid - 1;
            }
        }

        return left;
    }
};
