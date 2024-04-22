class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size();
        
        for(int i=0; i<n; i++){
            int t = 0;
            for(int j=i; j<n; j++){
                t |= nums[j];
                if(t >= k){
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};