class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, found = -1;
        
        //binary search to find an instance of target
        while(left <= right){
            int mid = (right + left)/2;
            if(nums[mid] == target){
                found = mid;
                break;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        if(found == -1) return {-1,-1};

        int left_target = found, right_target = found;

        while(left_target - 1 >= 0 && nums[left_target-1] == target) left_target--;
        while(right_target + 1 < nums.size() && nums[right_target+1] == target) right_target++;

        return {left_target, right_target};
    }
};