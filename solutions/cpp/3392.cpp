class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if(n < 3) return 0;
        
        for(int i=2; i<n; i++){
            double two_sum = nums[i-2] + nums[i];
            double half = (double)nums[i-1]/2;
            if(two_sum == half) ans++;
        }

        return ans;
    }
};
