class Solution {
public:
    int MOD = 1'000'000'007;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0, j=nums.size()-1, ans = 0;
        vector<int> pows(nums.size(),1);
        for(int i=1; i<nums.size(); i++) pows[i] = pows[i-1]*2%MOD;
        while(i <= j){
            if(nums[i]+nums[j] > target){
                j--;
            } else {
                ans = (ans + pows[j-i++]) % MOD;
            }
        }
        return ans;
    }
};
