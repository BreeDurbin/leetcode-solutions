class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int zeroes = 0;
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) zeroes++;
            else zeroes = 0;
            sum += zeroes;
        }
        return sum;
    }
};
