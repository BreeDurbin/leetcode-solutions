class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int m = nums.size() - 1;
        int i=m;
        bool carry = true;

        for(; i>=0; i--){
            if(carry){
                nums[i]++;
                carry = false;
            }
            if(nums[i] == 10){
                nums[i] = 0;
                carry = true;
            }
            else break;
        }

        if(carry){
            nums[0] = 0;
            nums.insert(nums.begin(), 1);
        }

        return nums;

    }
};
