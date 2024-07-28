class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i=0; i< nums.size(); i++){
            //track numbers which appeared one time
            // remove all twos once they are added to the twos array on the next iteration
            ones ^= (nums[i] & ~twos);
            //track numbers which appeared two times
            // only add to this list if it hasnt appeared in ones yet
            twos ^= (nums[i] & ~ones);
        }
        return ones;
    }
};