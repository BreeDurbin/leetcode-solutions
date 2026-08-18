class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;

        unordered_map<int,int> f;

        for(auto num : nums){
            f[num]++;
        }

        if(k == 1){
            for(auto [key, value] : f){
                if(value == 1) ans = max(ans, key);
            }
        }

        if(k == nums.size()){
            for(auto [key, value] : f){
                ans = max(ans, key);
            }
        }

        if(k > 1 && k < nums.size()){
            if(f[nums[0]] == 1 && f[nums[nums.size() - 1]] == 1) ans = max(nums[0], nums[nums.size() - 1]);
            else if(f[nums[0]] == 1) ans = nums[0];
            else if(f[nums[nums.size() - 1]] == 1) ans = nums[nums.size() - 1];
        }

        return ans;
    }
};
