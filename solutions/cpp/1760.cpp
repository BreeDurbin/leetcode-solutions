class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *std::max_element(nums.begin(), nums.end());
        while(left < right){
            int mid = (left + right) / 2;
            if(isDivisible(nums, mid, maxOperations)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool isDivisible(vector<int>& nums, int target, int maxOps){
        int ops = 0;
        for(auto num: nums){
            ops += (num + target - 1)/target - 1;
            if(ops > maxOps) return false;
        }

        return true;
    }
};
