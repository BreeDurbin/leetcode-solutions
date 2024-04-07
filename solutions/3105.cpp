class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 1) return 1;
        
        for(int i=1; i<n; i++){
            int count = 1;
            while(i < n && nums[i-1] < nums[i]){
                count++;
                i++;
            }
            ans = max(ans, count);
        }
        
        for(int i=1; i<n; i++){
            int count = 1;
            while(i < n && nums[i-1] > nums[i]){
                count++;
                i++;
            }
            ans = max(ans, count);
        }
        
        return ans;
        
    }
};