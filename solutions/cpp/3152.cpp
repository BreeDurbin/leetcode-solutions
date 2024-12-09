class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), n = nums.size();
        vector<int> parity(n);
        vector<bool> ans(m);
        parity[0] = 0;

        for(int i=1; i<n; i++){
            if(nums[i] % 2 ==  nums[i-1] % 2){
                parity[i] = parity[i-1] + 1;
            } else {
                parity[i] = parity[i-1];
            }
        }

        for(int i = 0; i < m; i++){
            int start = queries[i][0], end = queries[i][1];
            ans[i] = parity[end] - parity[start] == 0;
        }

        return ans;
        
    }
};
