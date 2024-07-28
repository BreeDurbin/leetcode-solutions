class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cache; // target -> count
        int ans = 0, sum = 0;
        cache[0]++;
        for(auto &num : nums){
            sum += num;
            // sum - prev = k -> sum - k = prev
            // where prev is the sum of indexes of a previous index
            if(cache[sum - k]) ans += cache[sum - k];
            cache[sum]++;
        }
        return ans;
    }
};