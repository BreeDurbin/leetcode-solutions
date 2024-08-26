class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = l + (r - l)/2;
            if(nums[m] > m){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
