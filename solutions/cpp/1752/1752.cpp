class Solution {
public:
    bool check(vector<int>& nums) {
        int drops = 0, m = nums.size();
        for(int i=0; i<m; i++){
            if(nums[i] > nums[(i+1)%m]){
                drops++;
            }
        }

        return drops <= 1;
    }
};
