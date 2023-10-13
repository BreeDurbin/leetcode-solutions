class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[1] < nums[0]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        int left=1, right=nums.size()-2;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            if(nums[mid]<nums[mid+1]){
                left=mid+1;
            } else {
                right=mid-1;
            }
        }
        return -1;
    }
};