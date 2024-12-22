class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0, minusK = k * -1;
        vector<int> used;
        sort(nums.begin(), nums.end());
        
        for(auto num : nums){
            int smol = num + minusK;
            if(used.size() == 0){
                used.push_back(smol);
                continue;
            }
            if(used.back() >= num + k) continue;
            used.push_back(max(smol, used.back() + 1));
        }

        return used.size();
    }
};
