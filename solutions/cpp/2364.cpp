class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total_pairs = (long long)n * (n - 1) / 2, good_pairs = 0;
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            freq[nums[i] - i]++;
        }

        for(auto & [k, f] : freq) if(f > 1) good_pairs += (long long)f*(f-1)/2;

        return total_pairs - good_pairs;
    }
};
