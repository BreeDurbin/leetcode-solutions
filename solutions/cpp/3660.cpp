class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), prefix_max(n, 0), suffix_min(n, 0);
        prefix_max[0] = nums[0];
        suffix_min[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            prefix_max[i] = max(prefix_max[i-1], nums[i]);
            suffix_min[n-i-1] = min(suffix_min[n-i], nums[n-i-1]);
        }

        ans[n-1] = prefix_max[n-1];

        for(int i=n-2; i >= 0; i--){
            ans[i] = prefix_max[i];
            if(ans[i] > suffix_min[i+1]) ans[i] = ans[i+1];
        }

        return ans;
    }

};
