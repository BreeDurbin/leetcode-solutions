class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int m = nums.size();

        for(int i=1; i<m; i++){
            if(nums[i] % 2 == nums[i-1] % 2) return false;
        }
        
        return true;
    }
};
