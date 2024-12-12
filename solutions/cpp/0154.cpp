class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums);
    }

    int binarySearch(vector<int>& nums){
        int left = 0, right = nums.size() - 1;

        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else if (nums[mid] < nums[right]){
                right = mid;
            } else {
                right -= 1;
            }
        }

        return nums[left];
    }
};
