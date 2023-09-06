class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if(nums.size() == 0) return 0;
        if(nums.size() == 1 && nums[0] == val) return 0;
        if(nums.size() == 1 && nums[0] != val) return 1;

        int index = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        
        return index;
    }
};