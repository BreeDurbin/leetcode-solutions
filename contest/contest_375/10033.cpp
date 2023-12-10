class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), big = nums[0];
        long long ans = 0;
        for(int i=1; i<n; i++){
            big = max(big, nums[i]);
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] == big){
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }
        
        int bigness = 0, r = 0;
        for(int l=0; l<n; l++){
            while(bigness < k && r < n){
                if(nums[r]) bigness++;
                r++;
            }
            if(bigness == k) ans += n - r + 1;
            if(nums[l]) bigness--;
        }
        
        return ans;
    }
};