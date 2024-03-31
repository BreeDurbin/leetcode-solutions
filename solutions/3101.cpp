class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(j==i || nums[j-1] != nums[j]){
                    ans++;
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};