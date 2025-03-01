class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int m = nums.size();

        for(int i=0; i<m-1; i++) if(nums[i] == nums[i+1]){ nums[i] *= 2; nums[i+1] = 0; }
        for(int i=0; i<m-1; i++) if(nums[i] == 0){
            int j = i+1;
            while(j < m - 1 && nums[j] == 0) j++;
            swap(nums[i], nums[j]);
        }

        return nums;
    }
};
