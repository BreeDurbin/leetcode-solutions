class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            int mid = (left + right) / 2;
            bool isEven = (right - mid) % 2 == 0;

            if(nums[mid] == nums[mid + 1]){ 
                if(isEven) left = mid + 2;
                else right = mid - 1;
            } else if(nums[mid] == nums[mid-1]) {
                if(isEven) right = mid - 2;
                else left = mid + 1;
            } else {
                return nums[mid];
            }

        }

        return nums[left];
    }
};
