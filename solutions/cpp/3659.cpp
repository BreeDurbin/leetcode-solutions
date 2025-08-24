class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(n % k != 0) return false;

        unordered_map<int,int> f;
        for(auto num : nums) f[num]++;

        for(auto & [num, freq] : f) if(freq > n / k) return false;
        
        return true;
    }
};
