class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> f;
        //seed freq map
        for(int i=0; i<nums.size(); i++) f[nums[i]]++;
        // update ans if k and k+1 exist in freq map
        for(auto & [k, v] : f) if(f.find(k+1) != f.end()) ans = max(ans, f[k] + f[k+1]);

        return ans;
    }
};
