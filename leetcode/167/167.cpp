class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1; 
        while(start<end){
            if(nums[start]+nums[end] > target){
                end--;
            } else if(nums[start]+nums[end] < target){
                start++;
            } else {
                break;
            }
        }
        vector<int> v = {start+1,end+1};
        return v;
    }
};