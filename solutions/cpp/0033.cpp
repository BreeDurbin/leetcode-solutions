class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = nums.size()-1;

        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] >= nums[n - 1]){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }

        int left_search = binarySearch(nums, 0, max(l - 1, 0), target);
        if(left_search != -1) return left_search;
        return binarySearch(nums, min(l, n - 1), n - 1, target);
    }

    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
