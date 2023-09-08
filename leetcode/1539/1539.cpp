class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        for(int i=0; i<nums.size();i++){
            if(nums[i]<=k){
                k++;
            }
        }
        return k;
    }
};